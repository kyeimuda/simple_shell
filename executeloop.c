#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int execute_loop(void)
{
char *ar[] = {"./hsh", NULL};
execve(ar[0], ar, NULL);
return 0;
}
