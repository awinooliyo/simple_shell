#include "main.h"

/**
 * free_argv - A function that frees memory allocated for argv
 *
 * @argv: array of arguments
 */

void free_argv(char **argv)
{
	int a = 0;

	while (argv[a] != NULL)
	{
		free(argv[a]);
		a++;
	}
	free(argv);
}
