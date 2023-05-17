#include "main.h"

#define BUFFER_SIZE 1024
#define MAX_ARG 20

/**
 * _prompt - A function that displays a prompt
 *
 * @av: argument vector
 * @env: variable environment
 *
 */

void _prompt(char **av, char **env)
{
	char *str = NULL;
	size_t n = 0;
	ssize_t read;
	char *argv[MAX_ARG];
	char path_command[PATH_MAX];

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("EWShell$ ");
			fflush(stdout);
		}

		read = getline(&str, &n, stdin);

		if (read == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}

		str[strcspn(str, "\n")] = '\0';

		tokenize_input(str, argv);

		if (find_command(argv[0], env, path_command) == 0)
		{
			{
				execute_command(av, env, path_command, argv);
			}
		}
		else
		{
			 printf("%s: Command not Found\n", argv[0]);
		}
	}
}

/**
 * tokenize_input - A function that tokenizes user input
 *
 * @str: user input string
 * @argv: array of arguments
 *
 */

void tokenize_input(char *str, char **argv)
{
	int a = 0;
	char *tok;

	tok = strtok(str, " ");
	while (tok && a < MAX_ARG - 1)
	{
		argv[a] = tok;
		a++;
		tok = strtok(NULL, " ");
	}
	argv[a] = NULL;

	if (strcmp(argv[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}

/**
 * execute_command - A function that executes a command
 *
 * @av: argument vector
 * @env: variable environment
 * @argv: array of arguments
 * @path_command: path to command
 *
 */

void execute_command(char **av, char **env, char *path_command, char **argv)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(path_command, argv, env) == -1)
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
