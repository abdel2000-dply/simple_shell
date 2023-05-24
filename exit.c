#include "shell.h"

int ex(char **arg, char *av)
{
    int exit_code;
    (void) av;

    exit_code = (isnumber(arg[1])) ? _atoi(arg[1]) : 100;

    _exit(exit_code);
    return (0);
} 