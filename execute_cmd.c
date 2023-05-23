#include "main.h"

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
		child_process(av, env, path_command, argv);
	}
	else
	{
		parent_process(pid, status, argv);
	}
}

/**
 * child_process - function to check the child process
 *
 * @av: argument vector
 * @env: environ variable
 * @path_command: path of command
 * @argv: array of arguments
 */

void child_process(char **av, char **env, char *path_command, char **argv)
{
	if (execve(path_command, argv, env) == -1)
	{
		perror(av[0]);
		free_argv(argv);
		exit(EXIT_FAILURE);
	}
}

/**
 * parent_process - parent process
 *
 * @pid: forking process
 * @status: checks for ststus
 * @argv: array of arguments to be checked
 */
void parent_process(pid_t pid, int status, char **argv)
{
	waitpid(pid, &status, 0);
	free_argv(argv);
}
