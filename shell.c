#include "shell.h"

/**
* intmode - interactive & non-interactive shell mode
* @av: argument vector
*/
void intmode(char **av)
{
	char **arg, **cmds, *line;
	int len, i;
	char *del;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);

		line = getcmd(STDIN_FILENO);
		len = _strlen(line);
		del = delimiter_collector(line, len);

		if (del != NULL)
		{
			cmds = split_string(line, len, del[0]);
			cmds = spliting_bydelimiter(cmds, del);
		}
		else {
			cmds = malloc(2 * sizeof(char *));
			cmds[0] = line;
			cmds[1] = NULL;
		}

		if (!cmds[0])
			continue;

		for (i = 0; cmds[i]; i++)
		{
			arg = split_string(cmds[i], _strlen(cmds[i]), ' ');

			exec_cmd(arg, av[0]);

			free(arg);
		}
		free(del);
		free(cmds);
	}
}

/**
* filemode - read from file shell mode
* @av: argument vector
*/
void filemode(char **av)
{
	int fd;
	char **cmds, *line;


	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		perror(av[1]);

	while ((line = getcmd(fd)) != NULL)
	{
		if (!line)
		continue;

		cmds = split_string(line, _strlen(line), ' ');
		exec_cmd(cmds, av[0]);
	}
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