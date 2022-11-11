#include "main.h"
#include <stdio.h>
#include <string.h>  
#include <malloc.h>

char* my_strtok(char* s, char* delm)
{
    
    char *W;
    int i;
        
    static int currIndex = 0;
    if(!s || !delm || s[currIndex] == '\0')
    return NULL;
    W = (char *)malloc(sizeof(char)*100);
    i = currIndex, k = 0, j = 0;

    while (s[i] != '\0'){
        j = 0;
        while (delm[j] != '\0'){
            if (s[i] != delm[j])
                W[k] = s[i];
            else goto It;
            j++;
        }

        i++;
        k++;
    }
It:
    W[i] = 0;
    currIndex = i+1;
    return W;
}
