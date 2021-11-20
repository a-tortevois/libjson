#ifndef LIB_H
#define LIB_H

#include <errno.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

#define LONG_MAX            2147483647L
#define LONG_MIN        (-LONG_MAX - 1L)

/** Convert a numeric string to its integer value */
static int parse_int(char *str, int *value) {
    int rc = 0;
    regex_t regex;
    if (regcomp(&regex, "^[-0-9]+$", REG_EXTENDED)) {
        fprintf(stderr, "Unable to compile the regex.\n");
        return -1;
    }
    if (regexec(&regex, str, 0, NULL, 0) == 0) {
        char *endptr;
        errno = 0; // to distinguish success/failure after call
        long int l_value = strtol(str, &endptr, 10);
        if (endptr != NULL && ((errno == ERANGE && (*value == LONG_MAX || *value == LONG_MIN)) || (errno != 0 && *value == 0))) {
            rc = -1;
            fprintf(stderr, "Conversion Error !\n");
            goto __error;
        }
        *value = (int) l_value;
    } else {
        rc = -1;
        fprintf(stderr, "Error: %s is not a Number\n", str);
    }
    __error:
    regfree(&regex);
    return rc;
}

/** include in ctype.h */
static int isxdigit(int c) {
    return ((c >= 0x30 && c <= 0x39) ||   // 0-9
            (c >= 0x41 && c <= 0x46) ||   // A-F
            (c >= 0x61 && c <= 0x66));    // a-f
}

/** Convert an ASCII char to its hexadecimal value */
static int atoh(const char c, int *i) {
    if (c >= 0x30 && c <= 0x39) {         // 0-9
        *i = c - 0x30;
        return 0;
    } else if (c >= 0x41 && c <= 0x46) {  // A-F
        *i = c - 0x41 + 0x0A;
        return 0;
    } else if (c >= 0x61 && c <= 0x66) {  // a-f
        *i = c - 0x61 + 0x0A;
        return 0;
    }
    return -1;
}

/** Unicode to UTF-8 char encoder */
static uc_to_utf8(int uc, unsigned char *dest) {
    if (uc < 0x00) {
        return 0;
    }
    if (uc < 0x80) {
        dest[0] = (unsigned char) uc;
        return 1;
    }
    if (uc < 0x800) {
        dest[0] = (unsigned char) (0xC0 + (uc >> 6));
        dest[1] = (unsigned char) (0x80 + (uc & 0x3F));
        return 2;
    }
    // Note: we allow encoding 0xd800-0xdfff here, so as not to change the API, however, these are actually invalid in UTF-8
    if (uc < 0x10000) {
        dest[0] = (unsigned char) (0xE0 + (uc >> 12));
        dest[1] = (unsigned char) (0x80 + ((uc >> 6) & 0x3F));
        dest[2] = (unsigned char) (0x80 + (uc & 0x3F));
        return 3;
    }
    if (uc < 0x110000) {
        dest[0] = (unsigned char) (0xF0 + (uc >> 18));
        dest[1] = (unsigned char) (0x80 + ((uc >> 12) & 0x3F));
        dest[2] = (unsigned char) (0x80 + ((uc >> 6) & 0x3F));
        dest[3] = (unsigned char) (0x80 + (uc & 0x3F));
        return 4;
    }
    return 0;
}

#endif //LIB_H
