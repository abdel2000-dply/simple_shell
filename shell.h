#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

extern char **environ;

int isnumber(char *s);
char *_strcat(char *dest, char *src);
void exec_cmd(char **arg, char *av);
char **getcmd();

#endif /* SHELL_H */
