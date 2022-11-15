#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void kash_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "kash: cd: missing argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("kash: cd");
        }
    }
}
