#include "shell.h"

/**
 * delimiter_collector - collects the detected delimiters
 * @s: a string
 * @len: the length of the string
 *
 * Return: a string containing the detected delimiters.
 */

char *delimiter_collector(char *s, int len)
{
	int i, j = 0;
	char *del = malloc(sizeof(char) * (len + 1));

	for (i = 0; i < len; i++)
	{
		if (s[i] == ';' || s[i] == '#')
		{
			del[j] = s[i];
			j++;
		}
	}
	if (j == 0)
	{
		free(del);
		return (NULL);
	}

	del[j] = '\0';

	return (del);
}
