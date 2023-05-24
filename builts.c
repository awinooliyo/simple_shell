#include "main.h"

/**
 * _builts - function for biltin command
 *
 * @argc: pointer to arguments
 * @argv: array of arguments
 *
 * Return: 0
 */

int _builts(int argc, char *argv[])
{
	char *home = getenv("HOME");
	char *prev = getenv("OLDPWD");
	char *dir = (argc > 1) ? argv[1] : home;

	if (dir[0] == '-')
	{
		dir = (prev != NULL) ? prev : home;
		printf("%s\n", dir);
	}

	if (chdir(dir) != 0)
	{
		fprintf(stderr, "Failed to change directory\n");
		return (1);
	}

	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", getcwd(NULL, 0), 1);

	return (0);
}
