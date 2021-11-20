#ifndef ASSERT_H
#define ASSERT_H

#define assert(test_msg, expr)                              \
    ((void) sizeof ((expr) ? 1 : 0), __extension__ ({       \
        printf(" %s: ", test_msg);                          \
        if (expr) {                                         \
            printf("\033[0;32m");                           \
            printf("Pass\n");                               \
            printf("\033[0m");                              \
        } else {                                            \
            printf("\033[0;31m");                           \
            printf("FAIL\n");                               \
            printf("\033[0m");                              \
            exit(EXIT_FAILURE);                             \
        }                                                   \
    }))

#endif //ASSERT_H
