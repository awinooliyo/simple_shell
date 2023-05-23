#include "main.h"


/**
 * printAlias - print alias string.
 * @aliasNode: an alias node.
 * Return: 0 on success, otherwise 1 on error.
 */

int printAlias(alias_t *aliasNode)
{
	if (aliasNode->value)
	{
		printf("%s = %s\n", aliasNode->name, aliasNode->value);
		printAlias(aliasNode->next);
	}

	return (0);
}

/**
 * alias - builtin alias command.
 * @infoT: structure containing the possible arguments.
 * Return: Always 0.
 */

int alias(info_t *infoT)
{
	int i;
	char *nameValue
	alias_t *aliasNode;

	if (infoT->argc == 1)
	{
		aliasNode = infoT->alias;
		while (aliasNode)
		{
			printAlias(aliasNode);
			aliasNode = aliasNode->next;
		}

		return (0);
	}

	for (i = 1; i < infoT->argc; i++)
	{
		nameValue = strchr(info->argv[i], '=');

		if (nameValue)
		{
			printAlias(makeAlias(infoT->argv[i], nameValue + 1));
		}
		else
		{
			aliasNode = node_starts_with(infoT->alias, infoT->argv[i], '=');			
			if (aliasNode)
			{
				printAlias(aliasNode);
			}
		}
	}
	return (0);
}


/**
 * makeAlias - creates a new alias object with given name and value.
 * @name: the name of the alias.
 * @value: the value of the alias.
 * Return: a pointer to the created alias or
 * NULL if memory allocation fails.
 */
alias_t *makeAlias(const char *name, const char *value)
{
	alias_t *alias = malloc(sizeof(alias_t));

	if (alias != NULL)
	{
		alias->name = strdup(name);
		alias->value = strdup(value);
		alias->next = NULL;
	}

	return (alias);
}

/**
 * freeAlias - deletes an alias to free memory.
 * @alias: the alias object to destroy.
 * Return: nothing.
 */

void freeAlias(alias_t *alias)
{
	if (alias != NULL)
	{
		free(alias->name);
		free(alias->value);
		free(alias);
	}
}
