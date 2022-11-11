#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void exec(char **args) {
    pid_t child_pid = fork();

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





int main() 
{

  char *line;
  char **tokens;

    while (true) {
        new_putchar('$');
        line = read_line();
        tokens = split_line(line);

        if (tokens[0] != NULL) {
            exec(tokens);
        }

        free(tokens);
        free(line);
    }
}

