#include "shell.h"

/**
 * ex - exiting
 * @arg: a pointer to a string of args.
 * @av: the name of the program.
 *
 * Return: ...
 */
int ex(char **arg, char *av)
{
	int exit_code;
	(void) av;

	exit_code = (isnumber(arg[1])) ? _atoi(arg[1]) : 100;

	free_array(arg);
	_exit(exit_code);
	return (0);
}
