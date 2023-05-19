#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

extern char **environ;

void exec_cmd(char **arg, char *av);
char **getcmd();
char **split_string(char *s, int n, char delimiter);

/* string manipulation */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

/* number manipulation */
int _atoi(char *s);
int _isdigit(int c);
int isnumber(char *s);

/* built-in commands */
void cd(char *arg, char *av);

#endif /* SHELL_H */
