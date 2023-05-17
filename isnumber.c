#include "shell.h"

int isnumber(char *s)
{
	int i = 0;
	
	if (!s)
		return (0);

	while (s[i])
	{
		if (isdigit(s[i++]) == 0)
			return (0);
	}
	return (1);
}
