#include "main.h"

/**
* we_cd - handles changing the current directory.
* @args: arguments passed.
* Return: 0 on success, otherwise error message.
*/

int we_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "cd: missing argument\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd error");
	}
	return (0);
}

/**
* we_env - displays the environment variables.
* @args: arguments passed.
* Return: 0 on success, otherwise error message.
*/

int we_env(char **args)
{
	int i = 0;
	char **env;

	if (args != NULL)
	{
		while (args[i] != NULL)
		{
			printf("Argument %d: %s\n", i, args[i]);
			i++;
		}
	}

	env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

/**
* we_help - offers help information about the shell.
* @args: arguments passed.
* Return: 0 on success, otherwise error message.
*/

int we_help(char **args)
{
	size_t i = 0;
	int a;

	if (args != NULL)
	{
		for (a = 0; args[a] != NULL; a++)
		{
			printf("Argument %d: %s\n", a, args[a]);
		}
	}

	printf("WE Simple Shell\n");
	printf("Supported builtin commands:\n");
	for (i = 0; i <= sizeof(builtin_funct) / sizeof(builtin_cmd); i++)
	{
		printf(" %s\n", builtins[i].name);
	}
	printf("Use the 'help' command to display the information herein.\n");
	return (0);
}

/**
* we_echo - builtin function for echo command.
* @args: arguments passed.
* Return: 0 on success, otherwise error message.
*/
int we_echo(char **args)
{
	int i;

	for (i = 1; args[i] != NULL; i++)
	{
		printf("%s ", args[i]);
	}
	printf("\n");
	return (0);
}

/**
* we_exit - exits the shell program.
* @args: arguments passed.
* Return: 0 on success, otherwise error message.
*/

int we_exit(char **args)
{
	if (args[1] != NULL)
	{
		int exit_code;

		exit_code = atoi(args[1]);
		exit(exit_code);
	}

	exit(0);
}
