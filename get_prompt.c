#include "main.h"

#define BUFFER_SIZE 1024
#define MAX_ARG 20

/**
 * get_prompt - A function that displays a prompt
 *
 * @av: argument vector
 * @env: variable environment
 *
 */

void get_prompt(char **av, char **env)
{
	char *str = NULL;
	size_t n = 0;
	ssize_t read;
	char *argv[MAX_ARG];
	pid_t pid;
	int status;
	int a;
	char *tok;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("EWShell$ ");

		read = getline(&str, &n, stdin);

		if (read == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		str[strcspn(str, "\n")] = '\0';
		
		a = 0;
		tok = strtok(str, " ");

		while (tok && a < MAX_ARG - 1)
		{
			argv[a] = tok;
			a++;
			tok = strtok(NULL, " ");
		}
		argv[a] = NULL;

		pid = fork();
		if (pid == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			printf("%s: No such file or directory\n", av[0]);
		}
		else
		{
			wait(&status);
		}
	}
}
