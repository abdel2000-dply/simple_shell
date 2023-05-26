#include "shell.h"
/**
 * split_string - a fucntion that splits a string.
 * @s: string.
 * @len: line length
 * @delim: delimiter
 * Return: pointer to an array of array.
 */

char **split_string(char *s, int len, char delim)
{
	char *word, **result = {NULL};
	int r_size, w_count, in_word, w_len, start, end, i;

	r_size = w_count = in_word = 0;
	start = end = -1;

	for (i = 0; i <= len; i++)
	{
		if (s[i] == delim || s[i] == '\0' || s[i] == '\t' || s[i] == '#')
		{
			if (in_word)
			{
				end = i;
				w_len = end - start;
				word = malloc(sizeof(char) * (w_len + 1));
				_memcpy(word, s + start, w_len);
				word[w_len] = '\0';
				result = _realloc_array(result, ++r_size);
				result[w_count] = word;
				w_count++, in_word = 0;
			}
		}
		else
		{
			if (!in_word)
				start = i, in_word = 1;
		}
		if (s[i] == '#')
			break;
	}

	result = _realloc_array(result, ++r_size);
	result[w_count] = NULL;

	return (result);
}
