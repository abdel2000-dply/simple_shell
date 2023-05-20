#include "shell.h"

char delimiter_chicker(char *s, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '#' || s[i] == '&' || s[i] == '|' || s[i] == ';')
			return s[i];
	}

	return '\0';
}

