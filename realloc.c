#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @new_size: the new size of the new memory block
 *
 * Return: a pointer with the new size, NULL if new_size is 0 and ptr no null
 */
void *_realloc(void *ptr, unsigned int new_size)
{
	char *s;
	char *p = ptr;
	unsigned int i;

	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	s = malloc(sizeof(char) * new_size);

	if (ptr == NULL)
		return (s);

	if (!s)
		return (NULL);

	for (i = 0; i < new_size; i++)
		s[i] = p[i];

	free(ptr);
	return (s);
}

/**
 * _realloc_array - reallocates a memory block using malloc and free
 * @array: pointer to an array of pointers previously allocated
 * @new_size: the new size of the new memory block
 *
 * Return: a pointer with the new size
 */
char **_realloc_array(char **array, int new_size)
{
	char **newArray = malloc(sizeof(char *) * new_size);
	int i;

	if (newArray == NULL)
	{
		printf("Memory allocation failed.\n");
		return (array);
	}

	for (i = 0; array && i < new_size - 1; i++)
		newArray[i] = array[i];

	free(array);

	return (newArray);
}
