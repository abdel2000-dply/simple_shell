#include "shell.h"

/**
 * spliting_bydelimiter - spliting a string by a delimiter
 * @cmds: a pointer to a string of commands.
 * @del: the delimiter to split by.
 * Return: the splited cmds.
 */
char **spliting_bydelimiter(char **cmds, char *del)
{
	char **new_cmds = NULL;
	char **splited_cmds;
	int num_cmds = 0;
	int i, j, k;

	for (i = 1; del[i] != '\0'; i++)
	{
		for (j = 0; cmds[j] != NULL; j++)
		{
			splited_cmds = split_string(cmds[j], _strlen(cmds[j]), del[i]);
			k = 0;
			while (splited_cmds[k] != NULL)
			{
				new_cmds = _realloc(new_cmds, (num_cmds + 1) * sizeof(char *));
				new_cmds[num_cmds] = splited_cmds[k];
				num_cmds++;
				k++;
			}
			free(splited_cmds);
		}
		new_cmds = _realloc(new_cmds, (num_cmds + 1) * sizeof(char *));
		new_cmds[num_cmds] = NULL;

		free(cmds);
		cmds = new_cmds;
	}

	return (cmds);
}
