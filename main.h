#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>  

struct builtin {
    char *name;
    void (*func)(char **args);
};

struct builtin builtins[] = {
    {"exit", kash_exit},
    {"cd", kash_cd},
};

int new_putchar(char);
char* read_line();
void exec(char **args);
char** split_line(char *line);
char *lsh_read_line(void);
char* my_strtok(char* s, char* delm);
void kash_cd(char **args);
void kash_exit();
int kash_num_builtins();

#endif

