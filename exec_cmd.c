#include "shell.h"

void exec_cmd(char **arg, char *av)
{
	char *bin_arg;

	if (!strcmp("cd", arg[0]))
	{
		cd(arg[1], av);
		return;
	}

	bin_arg = _strcat("/usr/bin/", arg[0]);
	if (!access(arg[0], F_OK) && !access(bin_arg, F_OK))
	{
		perror(av);
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
