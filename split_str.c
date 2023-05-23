#include "shell.h"
/**
 * split_string - a fucntion that splits a string.
 * @s: string.
 * Return: pointer to an array of array.
 */

char **split_string(char *s, int len, char delimiter)
{
	char **result = NULL;
	int r_size = 0, w_count = 0;
	int in_word = 0, w_len;
	int start = -1, end = -1;
	char *word;


	for (int i = 0; i <= len; i++)
	{
		if (s[i] == delimiter || s[i] == '\0'|| s[i] == '\t' )
		{
			if (in_word)
			{
				end = i, w_len = end - start;
				word = malloc(sizeof(char) * (w_len + 1));
				memcpy(word, s + start, w_len);
				word[w_len] = '\0';
				r_size = r_size + 1;
				result = realloc(result, sizeof(char*) * r_size);
				result[w_count] = word;
				w_count++, in_word = 0;
			}
			if (s[i] == '#')
				break;
		}
		else
		{
			if (!in_word)
				start = i, in_word = 1;
		}
	}

	r_size = r_size + 1;
	result = realloc(result, sizeof(char*) * r_size);
	result[w_count] = NULL;

	return result;
}
