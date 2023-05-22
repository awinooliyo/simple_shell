#include "main.h"


/**
* we_alias - adds an alias to the aliases linked list.
* @args: arguments passed to the alias command.
* Return: O on success otherwise error mesage.
*/

int we_alias(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "alias: missing argument\n");
	}
	else
	{
		add_alias(args[1], args[2]);
	}
	return (0);
}

/**
* we_unalias - removes an alias from an aliases linked list.
* @args: arguments passed to the alias command.
* Returns: 0 on success, otherwise error message.
*/

int we_unalias(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "unalias: missing argument\n");
	}
	else
	{
		remove_alias(alias[1]);
	}
	return (0);
}

/**
* add_alias - adds an alias to the aliases linked list.
* @name: name of alias to be added.
* @command: command of the alias.
* Return: nothing.
*/

void add_alias(const char *name, const char *command)
{
	alias *new_alias = (alias *)malloc(sizeof(alias));

	new_alias->name = strdup(name);
	new_alias->command = strdup(command);
	new_alias->next = NULL;

	if (aliases == NULL)
	{
		aliases = new_alias;
	}
	else
	{
		alias *temp = aliases;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_alias;
	}
}

/**
* remove_alias - removes an alias from an aliases linked list.
* @name: name of alias to be removed.
* Return: nothing.
*/

void remove_alias(const char *name)
{
	alias *prev = NULL;
	alias *curr = aliases;

	while (curr != NULL)
	{
		if (strcmp(curr->name, name) == 0)
		{
			if (prev == NULL)
			{
				aliases = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}
			free(curr->name);
			free(curr->command);
			free(curr);
			return;
		}

		prev = curr;
		curr = curr->next;
	}
}

/**
* display_aliases - displays the list of aliases.
* Return: nothing.
*/

void display_aliases(void)
{
	alias *temp = aliases;

	while (temp != NULL)
	{
		printf(%s = %s\n", temp->name, temp->command);
		temp = temp->next;
	}
}
