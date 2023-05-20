#include "shell.h"
/**
 * _strlen_recursion -  returns the length of a string
 * @s: pointer to a string
 *
 * Return: length of a string
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen(s + 1));
}
