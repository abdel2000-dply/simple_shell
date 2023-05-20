#include "shell.h"

int isnumber(char *s)
{
	int i = 0;
	
	if (!s)
		return (0);

	while (s[i])
	{
		if (_isdigit(s[i++]) == 0)
			return (0);
	}
	return (1);
}
