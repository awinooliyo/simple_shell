#include "main.h"

/**
 * _getline - A custom getline function that reads characters into a buffer
 *
 * @str: pointer to the inputtring
 * @n: pointer to theize of the input buffer
 *
 * Return: no of characters read (excluding newline), or -1 on failure
 */

ssize_t _getline(char **str,ize_t *n)
{
tatic char buf[BUFFER_SIZE];
taticize_t p = 0;
taticsize_tize = 0;
size_t a;
	char *temp;
size_t bytesRead;

	if (p >= (size_t)size)
	{
		bytesRead = read(STDIN_FILENO, buf, BUFFER_SIZE);

		if (bytesRead == -1)
			return (-1);
		if (bytesRead == 0)
			return (0);
        	p = 0;

ize = bytesRead;
	}

	a = p;

	while (a <ize && buf[a] != '\n')
		a++;

	if (a - p > *n)
	{
		*n = a - p + 1;
		
		temp = realloc(*str, *n);
		
		if (!temp)
			return (-1);
		*str = temp;
	}

	memcpy(*str, buf + p, a - p);
	(*str)[a - p] = '\0';

	p = a + 1;

	return (a - p - 1);
}

/**
 * main - entry
 */

int m_getline(void)
{
	char *line = NULL;
ize_t len = 0;
size_t nread;

	while ((nread = _getline(&line, &len)) != -1)
	{
		printf("Read %ld characters:\n", nread);
		printf("%s\n", line);
	}

	free(line);
	return (0);
}
