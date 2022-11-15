#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

struct builtin {
    char *name;
    void (*func)(char **args);
};

struct builtin builtins[] = {
    {"help", kash_help},
    {"exit", kash_exit},
    {"cd", kash_cd},
};

int kash_num_builtins() {
    return sizeof(builtins) / sizeof(struct builtin);
}
