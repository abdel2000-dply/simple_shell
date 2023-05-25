#include "shell.h"

/**
 * _memcpy - copies memory area
 * @dest: memory area
 * @src: memory area
 * @n: number of bytes
 *
 * Return: pointer to dest memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}