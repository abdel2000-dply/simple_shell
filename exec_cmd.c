#include "shell.h"

typedef struct builtin
{
	char *cmd;
	int (*func)(char **arg, char *av);
} builtin;

void exec_cmd(char **arg, char *av)
{
	char *bin_arg;
<<<<<<< HEAD
	int i = 0;
	builtin b[] = {
		{"cd", cd},
		{"exit", ex},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL},
	};
	while (b[i].cmd)
=======
	pid_t pid;

	if (!strcmp("cd", arg[0]))
	{
		cd(arg[1], av);
		return;
	}

	bin_arg = _strcat("/usr/bin/", arg[0]);
	if (!access(arg[0], F_OK) && !access(bin_arg, F_OK))
>>>>>>> c8a000a (adding cd built-in cmd)
	{
		if (!strcmp(b[i].cmd, arg[0]))
		{
			b[i].func(arg, av);
			return;
		}
		i++;
	}
	

	bin_arg = _strcat("/bin/", arg[0]);
	if (access(arg[0], F_OK) && access(bin_arg, F_OK))
	{
		dprintf(STDERR_FILENO, "%s: %s: command not found\n", av, arg[0]);
		return;
	}

<<<<<<< HEAD
	if (fork() == 0)
=======
	pid = fork();
	if (pid == 0)
>>>>>>> c8a000a (adding cd built-in cmd)
	{
		if (execve(arg[0], arg, NULL) == -1)
			execve(bin_arg, arg, environ);

		perror(av);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
