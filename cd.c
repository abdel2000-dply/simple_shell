#include "shell.h"

char last_dir[256] = {0};

void cd(char *arg, char *av)
{
	char *home, curr_dir[256];

	if (!arg)
	{
		getcwd(last_dir, sizeof(last_dir));
		home = getenv("HOME");
		chdir(home);
	}
	else if (!_strcmp("-", arg)) 
	{
		if (!last_dir[0])
		{
			printf("%s: cd: OLDPWD not set\n", av);
			return;
		}

		getcwd(curr_dir, sizeof(curr_dir));
		chdir(last_dir);
		printf("%s\n", last_dir);
		_strcpy(last_dir, curr_dir);
	}
	else
	{
		getcwd(curr_dir, sizeof(curr_dir));
		if (chdir(arg) == -1)
		{
			printf("%s: cd: ", av);
			fflush(stdout);
			perror(arg);
		}
		else
			_strcpy(last_dir, curr_dir);
	}
}
