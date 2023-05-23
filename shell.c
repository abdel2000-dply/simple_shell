#include "shell.h"

int main(int __attribute__((unused)) ac, char **av)
{
	char **arg, **cmds, *line;
	int exit_code, i, j, k;
	char *del;

	while (isatty(STDIN_FILENO))
	{
		printf("$ ");

		line = getcmd();
		j = _strlen(line);
		del = delimiter_collector(line, j);

		if (del != NULL)
		{
			cmds = split_string(line, j, del[0]);
			cmds = spliting_bydelimiter(cmds, del);
		}
		else {
			cmds = malloc(2 * sizeof(char *));
			cmds[0] = line;
			cmds[1] = NULL;
		}

		for (i = 0; cmds[i]; i++)
		{		
			k = _strlen(cmds[i]);
			arg = split_string(cmds[i], k, ' ');
			if (!arg[0])
			{
				free(arg);
				continue;
			}

			exit_code = (isnumber(arg[1])) ? _atoi(arg[1]) : 100;

			if (_strcmp("exit", arg[0]) == 0)
				_exit(exit_code);


			exec_cmd(arg, av[0]);
			free(arg);

		}
		free(del);
		free(cmds);
	}

	return (0);
}
