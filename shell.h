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

char **split_string(char *s, int n, char delimiter);

int _atoi(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _isdigit(int c);

#endif /* SHELL_H */
