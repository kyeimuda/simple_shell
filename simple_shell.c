#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

int main()
{
int status;
char *prompt = "USER@enter$$- ";
pid_t child_process;
pid_t parent_process = getppid();
char **argv;
int turn;
  
printf("%s", prompt);

argv =_args();

child_process = fork();
if(child_process == -1)
{
perror("Error:");
}
else if(child_process == 0)
{
if (execve(argv[0], argv, NULL) == -1)
{
perror("./hsh");
}
}
else
{
wait(&status);
free(argv);
turn = execute_loop();
}
return 0;
}
