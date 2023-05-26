#include "shell.h"

/**
 * intmode - interactive & non-interactive shell mode
 * @av: argument vector
 */
void intmode(char **av)
{
	char **arg, **cmds, *line;
	int len, i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);

		line = getcmd(STDIN_FILENO);
		len = _strlen(line);

		cmds = split_string(line, len, ';');

		for (i = 0; cmds[i]; i++)
		{
			arg = split_string(cmds[i], _strlen(cmds[i]), ' ');

			if (!arg[0])
				continue;

			exec_cmd(arg, av[0]);

			free_array(arg);
		}
		free(line);
		free_array(cmds);
	}
}

/**
 * filemode - read from file shell mode
 * @av: argument vector
 */
void filemode(char **av)
{
	char **cmds, *line;
	int fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		perror(av[1]);

	while ((line = getcmd(fd)) != NULL)
	{
		cmds = split_string(line, _strlen(line), ' ');
		if (!cmds[0])
			continue;

		exec_cmd(cmds, av[0]);

		free(line);
		free_array(cmds);
	}
	close(fd);
}

/**
 * main - the entry point of the program.
 * @ac: the number of command-line arguments
 * @av: an array of command-line argument strings
 *
 * Return: Always 0.
 */
int main(int __attribute__((unused)) ac, char **av)
{
	if (ac > 1)
		filemode(av);
	else
		intmode(av);

	return (0);
}
