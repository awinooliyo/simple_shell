#include "main.h"

/**
* write_output - writes output to stdout, stderr, and stdin
* @str: the string to write.
* @fd: file descriptor to write to.
*/

void write_output(char *str, int fd)
{
	size_t len = strlen(str);
	ssize_t written = 0;

	while (written < len)
	{
		ssize_t result = write(fd, str + written, len - written);

		if (result == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		written += result;
	}
}
