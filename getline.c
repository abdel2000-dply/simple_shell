#include "shell.h"

#define BUFF_SIZE 100

char *_getline(int fd)
{
	static char buff[BUFF_SIZE];
	static int buff_pos = 0, buff_size = 0;
	char *line = NULL;
	int line_size = 0;

	while (1) 
	{	
		if (buff_pos >= buff_size)
		{
			buff_pos = 0;
			buff_size = read(fd, buff, BUFF_SIZE);
			if (buff_size == -1)
			{
				perror("read");
				exit(EXIT_FAILURE);
			}

			if (buff_size == 0)
				break;
		}
		while (buff_pos < buff_size && buff[buff_pos] != '\n')
		{
			if (line_size % BUFF_SIZE == 0)
			{
				size_t new_size = line_size + BUFF_SIZE;
				line = realloc(line, new_size);
				if (line == NULL)
				{
					perror("realloc");
					exit(EXIT_FAILURE);
				}
			}
			line[line_size++] = buff[buff_pos++];
		}
		
		if (buff_pos < buff_size && buff[buff_pos] == '\n')
		{
			buff_pos++;
			line = realloc(line, line_size + 1);
			line[line_size] = '\0';
			return line;
		}
	}
	if (line_size > 0)
	{
		line[line_size] = '\0';
		return line;
	}
	return NULL;
}