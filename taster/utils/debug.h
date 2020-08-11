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

/*STANDARD OUTPUT*/
//function which prints a line in standard output a string argument:
void println(char *s){
    fprintf(stdout,"%s\n",s);
    fflush(stdout);
}

//function which prints in standard output a string argument:
void print(char *s){
    fprintf(stdout,"%s",s);
    fflush(stdout);
}

//function which prints integer in stdout:
void printI(char *s,int i){
    fprintf(stdout,"%s %d\n",s,i);
    fflush(stdout);
}

//function which prints float in stdout:
void printF(char *s,float f){
    fprintf(stdout,"%s %f\n",s,f);
    fflush(stdout);
}

//function which prints char in stdout:
void printC(char *s,char c){
    fprintf(stdout,"%s %c\n",s,c);
    fflush(stdout);
}

//function which prints double in stdout:
void printD(char *s,double d){
    fprintf(stdout,"%s %lf\n",s,d);
    fflush(stdout);
}

/*LOG FILE*/

//function that prints an output on a file named logfile.log in write mode
void printLog(char *output){
    FILE *fp;
    if(fp=fopen("logfile.log","w")){
        fprintf(fp,"%s",output);
    }else{
        fprintf(stderr,"Error opening file");
        fflush(stderr);
    }
    fflush(fp);
    fclose(fp);
}

//function that prints output in a file in write mode
void printFile(char *filename, char *output){
    FILE *fp;
    if(fp=fopen(filename,"w")){
        fprintf(fp,"%s",output);
    }else{
        fprintf(stderr,"Error opening file");
        fflush(stderr);
    }
    fflush(fp);
    fclose(fp);
}

//function that prints output in a file in chosen mode
void printFileM(char *filename, char *openmode, char *output){
    FILE *fp;
    if(fp=fopen(filename,openmode)){
        fprintf(fp,"%s",output);
    }else{
        fprintf(stderr,"Error opening file");
        fflush(stderr);
    }
    fflush(fp);
    fclose(fp);
}