#include "shell.h"

char **getcmd(int fd)
{
	char **arg, *line = NULL;
	
	line = _getline(fd);
	if (line == NULL)
		exit(0);

	arg = split_string(line, _strlen(line), ';');

	free(line);
	return (arg);
}
