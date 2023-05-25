#include "shell.h"

/**
 * err - prints error & exits
 * @error: error
 */
void err(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

/**
 * add_nullterm - adds '\0' to the end of a string
 * @line: ...
 * @line_size: ...
 * Return: null terminated line
 */
char *add_nullterm(char *line, int line_size)
{
	line[line_size] = '\0';
	return (line);
}
/**
 * _getline - reads an entire line.
 * @fd: file descriptor
 * Return: the read line
 */
char *_getline(int fd)
{
	static char buff[BUFF_SIZE];
	static int buff_pos, buff_size;
	char *line = NULL;
	int line_size = 0;

	while (1)
	{
		if (buff_pos >= buff_size)
		{
			buff_pos = 0;
			buff_size = read(fd, buff, BUFF_SIZE);
			if (buff_size == -1)
				err("read");
			if (buff_size == 0)
				break;
		}
		while (buff_pos < buff_size && buff[buff_pos] != '\n')
		{
			if (line_size % BUFF_SIZE == 0)
			{
				size_t new_size = line_size + BUFF_SIZE;

				line = _realloc(line, new_size);
				if (line == NULL)
					err("_realloc");
			}
			line[line_size++] = buff[buff_pos++];
		}

		if (buff_pos < buff_size && buff[buff_pos] == '\n')
		{
			buff_pos++;
			line = _realloc(line, line_size + 1);
			return (add_nullterm(line, line_size));
		}
	}
	if (line_size > 0)
		return (add_nullterm(line, line_size));
	return (NULL);
}
