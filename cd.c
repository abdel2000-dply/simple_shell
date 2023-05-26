#include "shell.h"


int erro(char *arg, char *av, int no);
char last_dir[256] = {0};
/**
 * cd - change directory
 * @arg: a pointer to a string of arg.
 * @av: the name of the program
 * Return: 0, -1 if error
 */
int cd(char **arg, char *av)
{
	char *home, curr_dir[256];
	char *pwd[] = {"", "PWD", ""};

	if (!arg[1])
	{
		getcwd(last_dir, sizeof(last_dir));
		home = _getenv("HOME");
		if (chdir(home))
			return (erro(arg[1], av, 0));
		pwd[2] = home;
		_setenv(pwd, av);

	}
	else if (!_strcmp("-", arg[1]))
	{
		if (!last_dir[0])
			return (erro(arg[1], av, 1));

		getcwd(curr_dir, sizeof(curr_dir));
		chdir(last_dir);
		printf("%s\n", last_dir);
		_strcpy(last_dir, curr_dir);
		getcwd(curr_dir, sizeof(curr_dir));
		pwd[2] = curr_dir;
		_setenv(pwd, av);
	}
	else
	{
		getcwd(curr_dir, sizeof(curr_dir));
		if (chdir(arg[1]) == -1)
			return (erro(arg[1], av, 2));
		_strcpy(last_dir, curr_dir);
		getcwd(curr_dir, sizeof(curr_dir));
		pwd[2] = curr_dir;
		_setenv(pwd, av);
	}
	return (0);
}

/**
 * erro - prints errors
 * @arg: ...
 * @av: ...
 * @no: ...
 * Return: ...
 */
int erro(char *arg, char *av, int no)
{
	if (no == 0)
		perror("cd");
	else if (no == 1)
		printf("%s: cd: OLDPWD not set\n", av);
	else if (no == 2)
	{
		dprintf(STDERR_FILENO, "%s: cd: ", av);
		fflush(stdout);
		perror(arg);
	}

	return (-1);
}
