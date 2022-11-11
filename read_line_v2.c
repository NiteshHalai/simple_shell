#define LSH_RL_BUFSIZE 1024

#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char *lsh_read_line(void)
{
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    exit(EXIT_FAILURE);
  }

  while (1) {

    c = getchar();


    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        exit(EXIT_FAILURE);
      }
    }
  }
}
