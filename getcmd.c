#include "shell.h"

char **getcmd()
{
	char **arg, *line, *word;
	size_t len = 0;
	int n, i = 1;

	n = getline(&line, &len, stdin);
	if (n == -1)
		exit(98);

	line[n - 1] = 0;
	arg = malloc(sizeof(char *));
	arg[0] = strtok(line, "\t ");

	do {
		word = strtok(NULL, "\t ");
		arg = realloc(arg, sizeof(char *) * i + 1);
		arg[i++] = word;

	} while (word);
	return (arg);
}
