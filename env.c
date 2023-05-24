#include "shell.h"

int _env(char **arg, char *av)
{
    int i = 0;
    (void) arg, av;

    while (environ[i])
        printf("%s\n", environ[i++]);

    return (0);    
}

char *_getenv(char *name)
{
    char **env = environ;
    int len;

    len = _strlen(name);
    while (*env)
    {
        if (!strncmp(*env, name, len))
            return (*env + ++len);
        env++;
    }

    return (NULL);
}

char *new_env_var(char *name, char *value)
{
    char *new_var = malloc(_strlen(name) + _strlen(value) + 2);

    if (!new_var)
        return (NULL);
    strcpy(new_var, name);
    strcat(new_var, "=");
    strcat(new_var, value);
    return (new_var);
}

int _setenv(char **arg, char *av)
{
    char **env, *name = arg[1], *value = arg[2];
    int len, size = 0;
    (void) av;

    len = _strlen(name);

    printf("%s\n%s\n", name, value);

    while (environ[size])
        size++;

    env = malloc(sizeof(char *) * (size + 1));
    size = 0;
    while (environ[size])
    {
        if (!strncmp(environ[size], name, len) && (*env)[len] == '=')
        {
            env[size] = malloc(_strlen(name) + _strlen(value) + 2);
            env[size] = new_env_var(name, value);
            size++;
            continue;
        }
        env[size] = malloc(_strlen(environ[size]) + 1);
        strcpy(env[size], environ[size]);
        size++;
    }

    if (!_getenv(name))
    {
        env = realloc(env, sizeof(char *) * (size + 2));
        env[size] = malloc(_strlen(name) + _strlen(value) + 2);
        env[size] = new_env_var(name, value);
        env[++size] = NULL;
        environ = env;
        return 0;
    }
    else
    {
        env[size] = NULL;
        environ = env;
        return 0;
    }
    return -1;
}

int _unsetenv(char **arg, char *av)
{
    char **env, *name = arg[1];
    int len, found = 0, size = 0, i = 0;
    (void) av;

    len = strlen(name);
    
    while (environ[size])
        size++;

    env = malloc(sizeof(char *) * (size + 1));
    size = 0;
    while (environ[size])
    {
        if (!strncmp(environ[size], name, len) && (*environ)[len] == '=')
        {
            found = 1;
            size++;
            continue;
        }
        env[i] = malloc(strlen(environ[size]) + 1);
        strcpy(env[i++], environ[size]);
        size++;
    }
    env[i] = NULL;

    if (found)
    {
        env = realloc(env, sizeof(char *) * size);
        environ = env;
        return (0);
    }

    return (-1);
}
