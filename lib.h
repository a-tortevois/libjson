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

#endif //LIB_H
