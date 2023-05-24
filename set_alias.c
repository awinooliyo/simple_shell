#include "main.h"

#define MAX_ALIASES 100

alias_t aliases[MAX_ALIASES];
int num_aliases = 0;

/**
 * print_alias - functionto print new alias
 *
 */
void print_aliases(void)
{
	int a;

	for (a= 0; a < num_aliases; a++)
	{
		printf("%s='%s'\n", aliases[a].name, aliases[a].value);
	}
}

/**
 * define_alias - defines a new alias
 *
 * @name: alias name given
 * @value: value of the alias
 */

void define_alias(char *name, char *value)
{
	int a;

	for (a = 0; a < num_aliases; a++)
	{
		if (strcmp(name, aliases[a].name) == 0)
		{
			free(aliases[a].value);
			aliases[a].value = strdup(value);
			return;
		}
	}
	if (num_aliases == MAX_ALIASES)
	{
		printf("Too many aliases defined.\n");
		return;
	}
	aliases[num_aliases].name = strdup(name);
	aliases[num_aliases].value = strdup(value);
	num_aliases++;
}

/**
 * handle_alias - handles the alias
 *
 * @args: array of arguments
 * @num_args: pointer to integer
 *
 */
void handle_alias(char **args, int num_args)
{
	int a;

       	if (num_args == 0)
	{
		print_aliases();
	}
	else if (num_args == 1)
	{
		for (a = 0; a < num_aliases; a++)
		{
			if (strcmp(args[0], aliases[a].name) == 0)
			{
				printf("%s='%s'\n", aliases[a].name, aliases[a].value);
				return;
			}
		}
		printf("Alias not found.\n");
	}
	else if (num_args == 2)
	{
		define_alias(args[0], args[1]);
	}
	else
	{
		printf("Invalid arguments.\n");
	}
}
