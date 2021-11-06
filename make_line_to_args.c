#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 *_args - tokenizes a sting.
 * return: pointer to the first token.
 */

int bytes_read;
size_t size = 10;
char *string;
int i;
char **argv = NULL;
char *tokens = NULL;
char delim[] = " \n\t";

char **_args(void)
{
  string = (char*) malloc(size);                 
  bytes_read = getline(&string, &size, stdin);   
  tokens = strtok(string, delim);                
  argv = (char**)malloc(bytes_read);             
  for(i = 0; tokens != NULL; i++)                
    {                                              
      argv[i] = strdup(tokens);
      tokens = strtok(NULL, delim);
    }argv[i] = tokens;

  return argv;
}
