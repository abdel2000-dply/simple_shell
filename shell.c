#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

int isNumber(char *s)
{
	int i;
	
	if (!s)
		return (0);

	for (i = 0; s[i]!= '\0'; i++)
	{
		if (isdigit(s[i]) == 0)
			return 0;
	}
	return 1;
}

char *_strcat(char *dest, char *src)
{
	int destlen, srclen;
	char *n;

	destlen = strlen(dest);
	srclen = strlen(src);
	n = malloc(sizeof(char) * (destlen + srclen + 1));
	strcpy(n, dest);

	while (*src)
		n[destlen++] = *src++;

	n[destlen] = '\0';
	return (n);

}

int main(int __attribute__((unused)) ac, char **av)
{
	char *line, *word, **arg, *bin_arg;
	size_t len = 0;
	pid_t pid;
	int i, exit_code;

	while (isatty(STDIN_FILENO))
	{
		i = 1;
		printf("$ ");

		if (getline(&line, &len, stdin) == -1)
			exit(98);

		line[strcspn(line, "\n")] = 0;
		arg = malloc(sizeof(char *));
		arg[0] = strtok(line, " ");

		do {
			word = strtok(NULL, " ");
			arg = realloc(arg, sizeof(char *) * i + 1);
			arg[i++] = word;

		} while (word);

		exit_code = (isNumber(arg[1])) ? atoi(arg[1]) : 100;
		
		if (strcmp("exit", arg[0]) == 0)
		{
			printf("%d", exit_code);
			_exit(exit_code);
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(arg[0], arg, NULL) == -1)
			{
				bin_arg = _strcat("/bin/", arg[0]);
				execve(bin_arg, arg, NULL);
			}

			perror(av[0]);
			exit(EXIT_FAILURE);
		}
		else
			wait(NULL);
		free(arg);
	}

	return (0);
}
