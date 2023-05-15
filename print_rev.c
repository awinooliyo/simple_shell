#include "main.h"

/**
 * print_rev - A function that prints strings in reverse
 *
 * @s:  pointer to the string
 */

void print_rev(char *s)
{
	int a, len;

	len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	for (a = len - 1; a >= 0; a--)
	{
		printf("%c", s[a]);
	}
	printf("\n");
}
