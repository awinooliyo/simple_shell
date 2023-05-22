#include "main.h"

#define BUFFER_SIZE 1024
#define MAX_ARG 40
/**
 * _prompt - A function that displays a prompt
 *
 * @av: argument vector
 * @env: variable environment
 *
 */

void _prompt(char **av, char **env)
{
	char *str;
	size_t n;
	ssize_t read;
	char *argv[MAX_ARG];
	char path_command[PATH_MAX];

	str = malloc(sizeof(char) * BUFFER_SIZE);
	n = BUFFER_SIZE;

	if (str == NULL)
	{
		perror("Error: Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

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
			break;
		}

		str[strcspn(str, "\n")] = '\0';

		tokenize_input(str, argv, MAX_ARG);

		if (argv[0] == NULL)
		{
			free_argv(argv);
			continue;
		}

		if (find_command(argv[0], env, path_command) == 0)
		{
			execute_command(av, env, path_command, argv);
		}
		else
		{
			printf("%s: Command not Found\n", argv[0]);
		}
	}
	free(str);
}

/**
 * tokenize_input - A function that tokenizes user input
 *
 * @str: user input string
 * @argv: array of arguments
 *
 */

void tokenize_input(char *str, char **argv, int max_args)
{
	int a = 0;
	char *tok;

	for (a = 0; a < max_args; a++)
	{
		argv[a] = NULL;
	}
	tok = strtok(str, " ");

	a = 0;
	while (tok && a < max_args - 1)
	{
		argv[a] = tok;
		a++;
		tok = strtok(NULL, " ");
	}
	argv[a] = NULL;

	if (argv[0] != NULL && strcmp(argv[0], "exit") == 0)
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
		perror("Error:Failed to fork");
		free_argv(argv);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(path_command, argv, env) == -1)
		{
			perror(av[0]);
			free_argv(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_argv(argv);
	}

}
