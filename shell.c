#include "shell.h"

int main(int __attribute__((unused)) ac, char **av)
{
	char **arg, **cmds;
	int exit_code, i, j;

	while (isatty(STDIN_FILENO))
	{
		printf("$ ");

		cmds = getcmd();
		for (i = 0; cmds[i]; i++)
		{
			j = _strlen(cmds[i]);

			arg = split_string(cmds[i], j, ' ');
			if (!arg[0])
				continue;

			exit_code = (isnumber(arg[1])) ? _atoi(arg[1]) : 100;

			if (_strcmp("exit", arg[0]) == 0)
				_exit(exit_code);

			exec_cmd(arg, av[0]);

			free(arg);
		}
		free(cmds);
	}

	return (0);
}
