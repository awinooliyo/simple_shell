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

	buff = malloc(_strlen(var) + _strlen(val) + 2);

	if (!buff)
	{
		return (1);
	}
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, val);
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
		node = (list_t *)node->next;
	}

	add_node((list_t **)&(envs->env), buff, 0);
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

	node = (list_t *) envs->env;

	if (!node || !var)
	{
		return (0);
	}

	while (node)
	{
		b = starts(node->str, var);

		if (b && *b == '=')
		{
			envs->change_env = dlt_node_at_ind((list_t **) &(envs->env), a);

			a = 0;
			node = envs->env;
			continue;
		}
		node = (list_t *) node->next;
		a++;
	}

	return (envs->change_env);
}

/**
 * _strcat - cancatenates 2 strings
 *
 * @src: source string
 * @dest: destination buffer
 *
 * Return: pointer to destination
 */

char *_strcat(char *dest, const char *src)
{
	size_t dest_len = strlen(dest);
	size_t a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[dest_len + a] = src[a];
		a++;
	}
	dest[dest_len + a] = '\0';
	return (dest);
}
