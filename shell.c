#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


int main() 
{

  char *line;
  char **tokens;

    while (true) {
        new_putchar('$');
        new_putchar(' ');
        line = lsh_read_line();
        tokens = split_line(line);

        if (tokens[0] != NULL) {
            exec(tokens);
        }

        free(tokens);
        free(line);
    }
}

