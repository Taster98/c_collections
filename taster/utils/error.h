#ifndef SORT_H
#define SORT_H
#endif
#ifndef STDIO_H
#define STDIO_H
#endif
#ifndef STDLIB_H
#define STDLIB_H
#endif
#ifndef STRING_H
#define STRING_H
#include "string.h"
#endif
#ifndef ERROR_H
#define ERROR_H
#endif

/* Macro which controls if there is a -1 error, prints it and exit */
#define ec_less1(s,m) \
    if((s)==-1){ \
        perror(m); \
        exit(EXIT_FAILURE); \
    }

/* Macro which controls if there is a 0 error, prints it and exit */
#define ec_zero(s,m) \
    if((s)!=0){ \
        perror(m); \
        exit(EXIT_FAILURE); \
    }

/* Macro which controls if there is a NULL error, prints it and exit */
#define ec_null(s,m) \
    if((s) == NULL){ \
        fprintf(stderr, m "\n"); \
    }