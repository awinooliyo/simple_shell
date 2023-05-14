#include "main.h"

/**
 * main - check code
 *
 * Return: 0
 */
int prompt(int ac, char **av, char **env)
{
        if (ac == 1)
        {
                get_prompt(av, env);
        }
        return (0);
}
