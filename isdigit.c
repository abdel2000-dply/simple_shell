#include "shell.h"
/**
 * _isdigit - checks for digits
 * @c: input as an integer
 *
 * Return: 1 for digits. 0 if not
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);

	return (0);
}
