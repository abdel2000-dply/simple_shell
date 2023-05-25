#include "shell.h"

/**
 * exec_cmd - handls the execution of a command.
 * @arg: a pointer to a string of args.
 * @av: the name of the program
 */
void exec_cmd(char **arg, char *av)
{
	char *bin_arg;
	int i = 0;
	builtin b[] = {
		{"cd", cd},
		{"exit", ex},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL},
	};
	while (b[i].cmd)
	{
		if (!_strcmp(b[i].cmd, arg[0]))
		{
			b[i].func(arg, av);
			return;
		}
		i++;
	}

	bin_arg = _strcat("/bin/", arg[0]);
	if (access(arg[0], F_OK) && access(bin_arg, F_OK))
	{
		dprintf(STDERR_FILENO, "%s: %s: command not found\n", av, arg[0]);
		return;
	}

	if (fork() == 0)
	{
		if (execve(arg[0], arg, NULL) == -1)
			execve(bin_arg, arg, environ);

		perror(av);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
