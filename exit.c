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
	(void)av;

	exit_code = (!arg[1]) ? 0 : 2;
	exit_code = (isnumber(arg[1])) ? _atoi(arg[1]) : exit_code;
	if (_atoi(arg[1]) < 0)
		dprintf(STDERR_FILENO, "%s: 1: exit: Illegal number: %s\n", av, arg[1]);

	if (!arg)
	{
		free_array(arg);
		free_array(environ);
	}
	_exit(exit_code);
	return (0);
}
