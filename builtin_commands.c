#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

builtin_cmd builtins[] = {
	{"cd", we_cd},
	{"env", we_env},
	{"help", we_help},
	{"echo", we_echo},
	{"exit" we_exit}
};

/**
* we_cd - an inbuilt function for the cd command.
* it handles changing the current directory.
*/

int we_cd(char **args)
{
	if (args[1] == NULL)
		printf(stderr, "cd: missing argument\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd error");
	}
	return (0);
}

/**
* we_env - built in function for the env command.
* it displays the environment variables.
*/

int we_env(char **args)
{
	char **env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

/**
* we_help - builtin function for the help command.
* it offers help information about the shell.
*/

int we_help(char **args)
{
	size_t i;
	printf("WE Simple Shell\n");
	printf("Supported builtin commands:\n");
	for (i = 0; i < sizeof(builtin_funct) / sizeof(builtin_cmd); i++)
	{
		printf(" %s\n", builtins[i].name);
	}
	_puts("Use the 'help' command to display the information herein.\n");
	return (0);
}

/**
* we_echo - builtin function for echo command
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