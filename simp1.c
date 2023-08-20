#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
char *line = NULL;
size_t len = 0;
ssize_t read;
while (1)
{
printf("$ ");
read = getline(&line, &len, stdin);
if (read != -1)
{
printf("%s", line);
}
else if (read == -1)
{
break;
}
}
}
