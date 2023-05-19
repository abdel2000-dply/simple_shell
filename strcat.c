#include "shell.h"

char *_strcat(char *dest, char *src)
{
	int destlen, srclen;
	char *n;

	destlen = strlen(dest);
	srclen = strlen(src);
	n = malloc(sizeof(char) * (destlen + srclen + 1));
	strcpy(n, dest);

	while (*src)
		n[destlen++] = *src++;

	n[destlen] = '\0';
	return (n);
}
