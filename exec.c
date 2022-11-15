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
    {"exit", kash_exit},
    {"cd", kash_cd},
};

int kash_num_builtins() {
    return sizeof(builtins) / sizeof(struct builtin);
}

void exec(char **args) {
    
    pid_t child_pid = fork();
    int i;
    
    for (i = 0; i < kash_num_builtins(); i++) {
       if (strcmp(args[0], builtins[i].name) == 0) {
            builtins[i].func(args);
            return;
        }
    }

    if (child_pid == 0) {
        execvp(args[0], args);
        perror("kash");
        exit(1);
    } else if (child_pid > 0) {
        int status;
        do {
            waitpid(child_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        perror("kash");
    }
}
