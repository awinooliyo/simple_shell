#include "main.h"

/**
 * _setenv - initializes new environment variable
 *
 * @envs: potential arguments in structure
 * @var: variable property of string
 * @val: value of env string
 *
 * Return: 0
 */
int _setenv(environ_t *envs, char *var, char *val)
{
	char *buff = NULL;
	list_t *node = NULL;
	char *b = NULL;

	if (!var || !val)
	{
		return (0);
	}

	buff = malloc(i_strlen(var) + i_strlen(val) + 2);

	if (!buff)
	{
		return (1);
	}
	i_strcpy(buff, var);
	i_strcat(buff, "=");
	i_strcat(buff, val);
	node = envs->env;

	while (node)
	{
		b = starts(node->str, var);
		if (b && *b == '=')
		{
			free(node->str);
			node->str = buff;
			envs->change_env = 1;
			return (0);
		}
		node = node->next;
	}

	add_node(&(envs->env), buff, 0);
	free(buff);
	envs->change_env = 1;

	return (0);
}

/* UNSET THE ENV */

/**
 * _unsetenv - removes environment variable
 *
 * @envs: structure with potential arguments
 * @var: string env variable
 *
 * Return: 1 otherwise delete
 */
int _unsetenv(environ_t *envs, char *var)
{
	size_t a = 0;
	char *b = NULL;
	list_t *node = NULL;

	node = envs->env;

	if (!node || !var)
	{
		return (0);
	}

	while (node)
	{
		b = starts(node->str, var);

		if (b && *b == '=')
		{
			envs->change_env = dlt_node_at_ind(&(envs->env), a);

			a = 0;
			node = envs->env;
			continue;
		}
		node = node->next;
		a++;
	}
	return (envs->change_env);
}
