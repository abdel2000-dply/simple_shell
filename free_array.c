#include "shell.h"
/**
 * free_array - deallocats an array of pointers
 * @array: array of pointers
 */
void free_array(char **array)
{
	int i = 0;

	if (!array)
		return;

	while (array[i])
		free(array[i++]);

	free(array);
}
