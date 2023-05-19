#include "shell.h"

char **getcmd()
{
	char **arg, *line, *word;
	size_t len = 0;
	int n, i = 1;

	n = getline(&line, &len, stdin);
	if (n == -1)
		exit(98);

	line[n - 1] = '\0';
	// make a checker function to get the delimiter
	arg = split_string(line, n - 1, ';');

	return (arg);
}
