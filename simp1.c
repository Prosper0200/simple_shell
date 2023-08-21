#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
pid_t child_pid;
int status;
char *line = NULL;
size_t len = 0;
ssize_t read;
while (1)
{
printf("$ ");
read = getline(&line, &len, stdin);
if (read != -1)
{
child_pid = fork();
if (child_pid == -1)
{
perror("Error:");
printf("\n");
exit(1);
}
if (child_pid == 0)
{
char *arg[] = {line, NULL};
if (execve("/bin/sh", arg, NULL) == -1)
{
perror("Error");
}
exit(0);
}
else
{
wait(&status);
}
}
else if (read == -1)
{
break;
}
}
return (0);
}
