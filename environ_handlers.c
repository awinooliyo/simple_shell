#include "main.h"

/* ADD NODE */
/**
 * add_node - add new node at the end of linked list
 *
 * @head: pointer to head of linked list
 * @str: string value of new node
 * @change_env: value of new node
 *
 * Return: address of new node else NULL
 */

list_t *add_node(list_t **head, const char *str, int change_env)
{
	list_t *new_node, *last;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->change_env = change_env;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		last = *head;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new_node;
	}

	return (new_node);
}

/**
 * dlt_node_at_ind - delete node at given index
 *
 * @head: pointer to linked list head
 * @ind: index of node to delete
 *
 * Return: 1 if successful, else 0 if out of range
 */

int dlt_node_at_index(list_t **head, size_t ind)
{
	size_t a;
	list_t *pre;
	list_t *curr;

	pre = NULL;
	curr = *head;

	while (curr && a < ind)
	{
		pre = curr;
		curr = curr->next;
		a++;
	}

	if (curr == NULL)
		return (0);

	if (pre != NULL)
	{
		prre->next = curr->next;
	}
	else
		*head = curr->next;

	free(curr->str);
	free(curr);

	return (1);
}

/* STRARTS */

/**
 * starts - check if string start with a given prefix
 *
 * @str: string to be checked
 * @prefix: prefix to be matched
 *
 * Return: pointer to position in str else NULL
 */

char *starts(const char *str, const char *prefix)
{
	size_t str_len = strlen(str);
	size_t prefix_len = strlen(prefix);

	if (str_len < prefix_len)
	{
		return (NULL);
	}
	if (strncmp(str, prefix, prefix_len) == 0)
	{
		return (*str);
	}
	else
		return (NULL);

}

/* STRLEN */

/**
 * i_strlen - calculates string length
 *
 * @str: input strin
 *
 * Return: length of string
 */
size_t i_strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * i_strcpy - copies string
 *
 * @src: source string
 * @dest: destination of buffer
 *
 * Return: pointer to destination
 */

char *i_strcpy(char *dest, const char *src)
{
	size_t a;

	a = 0;

	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * i_strcat - cancatenates 2 strings
 *
 * @src: source string
 * @dest: destination buffer
 *
 * Return: pointer to destination
 */

char *i_strcat(char *dest, const char *src)
{
	size_t dest_len = strlen(dest);
	size_t a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[dest_len + a] = src[a];
		a++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
