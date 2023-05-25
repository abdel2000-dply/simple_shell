/**
 * _strncmp - compares two strings
 *
 * @s1: the first string
 * @s2: the second string
 * @n: length.
 * Return: the difference between the first two chars
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (n-- && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		i++;
	}
	return (0);
}