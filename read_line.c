#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* read_line() {
    char *line = NULL;
    size_t buflen = 0;
    getline(&line, &buflen, stdin);
    return line;
}
