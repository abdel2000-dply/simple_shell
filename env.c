#include "shell.h"

/**
* _env - prints the current environment
* @arg: ...
* @av: ...
* 
* Return: 0 on success
*/
int _env(char **arg, char *av)
{
    int i = 0;
    (void) arg;
    (void) av;

    while (environ[i])
        printf("%s\n", environ[i++]);

    return (0);    
}

/**
* _getenv - gets the value of an env variable
* @name: name of the variable
*
* Return: the value of the @name env variable if it exists, otherwise null 
*/
char *_getenv(char *name)
{
    char **env = environ;
    int len;

    len = _strlen(name);
    while (*env)
    {
        if (!_strncmp(*env, name, len))
            return (*env + ++len);
        env++;
    }

    return (NULL);
}

/**
* new_env_var - creates a new env string
* @name: name of the env variable
* @value: value of the env variable
*
* Return: env string, or NULL
*/
char *new_env_var(char *name, char *value)
{
    char *new_var = malloc(_strlen(name) + _strlen(value) + 2);

    if (!new_var)
        return (NULL);
    _strcpy(new_var, name);
    strcat(new_var, "=");
    strcat(new_var, value);
    return (new_var);
}

/**
* _setenv - Initialize a new environment variable, or modify an existing one
* @arg: array that contains name & value of the env variable 
* @av: the name of the program.
*
* Return: 0 on success, -1 on failure
*/
int _setenv(char **arg, char *av)
{
    char **env, *name = arg[1], *value = arg[2];
    int len, size = 0;
    (void) av;

    len = _strlen(name);

    while (environ[size])
        size++;

    env = malloc(sizeof(char *) * (size + 1));
    size = 0;
    while (environ[size])
    {
        if (!_strncmp(environ[size], name, len) && environ[size][len] == '=')
        {
            env[size] = malloc(_strlen(name) + _strlen(value) + 2);
            env[size] = new_env_var(name, value);
            size++;
            continue;
        }
        env[size] = malloc(_strlen(environ[size]) + 1);
        _strcpy(env[size], environ[size]);
        size++;
    }

    if (!_getenv(name))
    {
        env = _realloc(env, sizeof(char *) * (size + 2));
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
/**
* _unsetenv - unsets the envirement.
* @arg: array that contains name & value of the env variable 
* @av: the name of the prgoram.
*
* Return: 0 on success, -1 on failure
*/
int _unsetenv(char **arg, char *av)
{
    char **env, *name = arg[1];
    int len, found = 0, size = 0, i = 0;
    (void) av;

    len = _strlen(name);
    
    while (environ[size])
        size++;

    env = malloc(sizeof(char *) * (size + 1));
    size = 0;
    while (environ[size])
    {
        if (!_strncmp(environ[size], name, len) && environ[size][len] == '=')
        {
            found = 1;
            size++;
            continue;
        }
        env[i] = malloc(_strlen(environ[size]) + 1);
        _strcpy(env[i++], environ[size]);
        size++;
    }
    env[i] = NULL;

    if (found)
    {
        env = _realloc(env, sizeof(char *) * size);
        environ = env;
        return (0);
    }

    return (-1);
}
