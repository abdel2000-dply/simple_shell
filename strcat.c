#include "shell.h"

/**
 * _strcat -  concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: string
 */

char *_strcat(char *dest, char *src)
{
	int destlen, srclen;
	char *n;

	destlen = _strlen(dest);
	srclen = _strlen(src);
	n = malloc(sizeof(char) * (destlen + srclen + 1));
	_strcpy(n, dest);

	while (*src)
		n[destlen++] = *src++;

	n[destlen] = '\0';
	return (n);
}