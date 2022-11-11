#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>  

int new_putchar(char);
char* read_line();
void exec(char **args);
char** split_line(char *line);
char *lsh_read_line(void);
char* my_strtok(char* s, char* delm);

#endif
