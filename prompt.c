#include "main.h"

/**
 * main - check code
 *
 * @ac: argument count
 * @av: argument vector
 * @env: environment variables
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		get_prompt(av, env);
	}
	return (0);
}
