#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

extern char **environ;

#define BUFF_SIZE 100

/**
 * struct builtin - ...
 * @cmd: command name
 * @func: function to execute the command
 */
typedef struct builtin
{
	char *cmd;
	int (*func)(char **arg, char *av);
} builtin;

void exec_cmd(char **arg, char *av);
char *getcmd(int fd);
char **split_string(char *s, int n, char delimiter);

/* string manipulation */
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);

/* number manipulation */
int _atoi(char *s);
int _isdigit(int c);
int isnumber(char *s);

/* built-in commands */
int cd(char **arg, char *av);
int ex(char **arg, char *av);
int _env(char **arg, char *av);
int _setenv(char **arg, char *av);
int _unsetenv(char **arg, char *av);

char *_getenv(char *name);
char *_getline(int fd);

char *delimiter_collector(char *s, int len);
char **spliting_bydelimiter(char **cmds, char *del);

/* memory managment*/
void *_realloc(void *ptr, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);


#endif /* SHELL_H */
