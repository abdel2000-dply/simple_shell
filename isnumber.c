#include "shell.h"

/**
* isnumber - checkes nums
* @s: a string.
*
* Return: 1 if s is a number, 0 otherwise.
*/
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
