#include "shell.h"

void intmode(char **av)
{
	char **arg, **cmds;
	int exit_code, i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);

		cmds = getcmd(STDIN_FILENO);

		if (!cmds[0])
			continue;

		for (i = 0; cmds[i]; i++)
		{
			arg = split_string(cmds[i], _strlen(cmds[i]), ' ');

			exit_code = (isnumber(arg[1])) ? _atoi(arg[1]) : 100;

			if (_strcmp("exit", arg[0]) == 0)
				_exit(exit_code);

			exec_cmd(arg, av[0]);

			free(arg);
		}
		free(cmds);
	}
}

void filemode(char **av)
{
	int fd;
	char **cmds, **arg;


	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		perror(av[1]);

	while ((cmds = getcmd(fd)) != NULL)
	{
		if (!cmds[0])
		continue;
		arg = split_string(cmds[0], _strlen(cmds[0]), ' ');
		exec_cmd(arg, av[0]);
	}
}

int main(int __attribute__((unused)) ac, char **av)
{
	if (ac > 1)
		filemode(av);
	else
		intmode(av);

	return (0);
}