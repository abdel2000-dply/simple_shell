#include "shell.h"

int main(int __attribute__((unused)) ac, char **av)
{
	char **arg;
	int exit_code;

	while (isatty(STDIN_FILENO))
	{
		printf("$ ");
		
		arg = getcmd();
		if (!arg[0])
			continue;

		exit_code = (isnumber(arg[1])) ? atoi(arg[1]) : 100;
		
		if (strcmp("exit", arg[0]) == 0)
			_exit(exit_code);
		
		exec_cmd(arg, av[0]);

		free(arg);
	}

	return (0);
}
