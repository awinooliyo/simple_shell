#include "main.h"

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
	char *argv[2];
	pid_t pid;
	int status;

	while (1)
	{
		printf("EWShell$ ");

		read = getline(&str, &n, stdin);

		if (read == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		str[strcspn(str, "\n")] = '\0';
		
		argv[0] = str;
		argv[1] = NULL;
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
