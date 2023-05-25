#include "shell.h"

/**
* getcmd - gets cmds from stdin
* @fd: file descriptor
*
* Return: readed line from stdin
*/
char *getcmd(int fd)
{
	char *line = NULL;

	line = _getline(fd);
	if (line == NULL)
		exit(0);

	return (line);
}
