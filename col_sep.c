#include "main.h"

#define TOKEN_BUFSIZE 64

/**
 * split - function handling sepearors
 *
 * @line: input line
 * @separator: character to split input line
 *
 * Return: pointer to toks
 */

char **split(char *line, char separator)
{
	char **toks = NULL;
	char *tok;
	int a, buffsize = TOKEN_BUFSIZE;

	if (!line)
		return (NULL);

	toks = malloc(buffsize * sizeof(char *));
	if (!toks)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line, &separator);
	for (a = 0; tok != NULL; a++)
	{
		toks[a] = tok;

		if (a >= buffsize)
		{
			buffsize += TOKEN_BUFSIZE;
			toks = realloc(toks, buffsize * sizeof(char *));
			if (!toks)
			{
				perror("realloc error");
				exit(EXIT_FAILURE);
			}
		}

		tok = strtok(NULL, &separator);
	}
	toks[a] = NULL;

	return (toks);
}
