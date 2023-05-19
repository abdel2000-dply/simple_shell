#include "shell.h"

int main(int __attribute__((unused)) ac, char **av)
{
	char **arg, **cmds;
	int exit_code, i, j;

	while (isatty(STDIN_FILENO))
	{
		printf("$ ");
		
		cmds = getcmd();
		for (i = 0; cmds [i]; i++)
		{
			for (j = 0; cmds[i][j] != '\0'; j++)
				;

			arg = split_string(cmds[i], j, ' ');
		if (!arg[0])
			continue;

		exit_code = (isnumber(arg[1])) ? atoi(arg[1]) : 100;
		
		if (strcmp("exit", arg[0]) == 0)
			_exit(exit_code);
		
		exec_cmd(arg, av[0]);

		free(arg);
		}
		free(cmds);
	}

	return (0);
}
