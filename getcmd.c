#include "shell.h"

char *getcmd()
{
	char **arg, *line, *word;
	size_t len = 0;
	int n, i = 1;
	char *del;

	n = getline(&line, &len, stdin);
	if (n == -1)
		exit(98);

	line[n - 1] = '\0';

	return (line);
}
