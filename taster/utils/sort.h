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

/*INTEGERS*/
//function to compare integers and sort in ascending order
int compareIntAsc(const void * x, const void * y){
    return ( *(int*)x - *(int*)y );
}
//function to compare integers and sort in descending order
int compareIntDesc(const void * x, const void * y){
    return ( *(int*)y - *(int*)x );
}

/*FLOAT AND DOUBLE*/
//function to compare float and sort in ascending order
int compareFloatAsc(const void * x, const void * y){
    return ( *(float*)x - *(float*)y );
}
//function to compare float and sort in descending order
int compareFloatDesc(const void * x, const void * y){
    return ( *(float*)y - *(float*)x );
}

//function to compare double and sort in ascending order
int compareDoubleAsc(const void * x, const void * y){
    return ( *(double*)x - *(double*)y );
}
//function to compare double and sort in descending order
int compareDoubleDesc(const void * x, const void * y){
    return ( *(double*)y - *(double*)x );
}

/*CHARS AND STRINGS*/
//function to compare char and sort in ascending order
int compareCharAsc(const void * x, const void * y){
    return ( *(char*)x - *(char*)y);
}
//function to compare char and sort in descending order
int compareCharDesc(const void * x, const void * y){
    return ( *(char*)y - *(char*)x);
}
//function to compare strings and sort in ascending order
int compareStringAsc(const void * x, const void * y){
    return strcmp(*(char**)x,*(char**)y);
}
//function to compare strings and sort in descending order
int compareStringDesc(const void * x, const void * y){
    return strcmp(*(char**)y,*(char**)x);
}