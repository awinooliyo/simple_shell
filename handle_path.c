#include "main.h"

/**
 * find_command - find command in directories specified
 *
 * @command: command to find
 * @env: variable environment
 * @path_command: path of the comand
 *
 * Return: -1 if command is not found else 0
 */
int find_command(char *command, char **env, char *path_command)
{
	char *path;
	char *copy_path;
	char *d;

	path = get_env("PATH", env);
	
	if (path == NULL)
		return (-1);

	copy_path = malloc(strlen(path) + 1);

	if (copy_path == NULL)
	{
		printf("Mem allocation error\n");
		return (-1);
	}

	d = strtok(path, ":");

	while (d != NULL)
	{
		snprintf(path_command, PATH_MAX, "%s%s", d, command);
		if (access(path_command, X_OK) == 0)
		{
			free(copy_path);
			return (0);
		}
		d =strtok(NULL, ":");
	}


	free(copy_path);
	return (-1);

}

/**
 * get_env - get value of environment variable
 *
 * @name: name of the environment variable
 * @env: variable environment
 *
 * Return: NULL if not found
 */

char *get_env(char *name, char **env)
{
	size_t len = strlen(name);
	char **ptr = env;

	while (*ptr != NULL)
	{
		if (strncmp(*ptr, name, len) == 0 && (*ptr)[len] == '=')
		{
			return (&((*ptr)[len + 1]));
		}
		ptr++;
	}

	return (NULL);
}
