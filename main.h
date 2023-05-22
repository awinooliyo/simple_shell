#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024


#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>

/**  FUNCTIONS PROTOTYPES */

void print_rev(char *s);
void get_prompt(char **av, char **env);
void tokenize_input(char *str, char **argv, int max_args);
void _prompt(char **av, char **env);
void free_argv(char **argv);
void execute_commands(char **env, char *path_command, char **argv);

/** Printing Strings **/
void _puts(char **strg);

/** Built in Functions **/
typedef int (*builtin_funct)(char **);
extern char **environ;
typedef struct {
        const char *name;
        builtin_funct funct;
} builtin_cmd;

builtin_cmd builtins[] = {
	{"cd", we_cd},
	{"env", we_env},
	{"help", we_help},
	{"echo", we_echo},
	{"exit", we_exit},
	{"alias", we_alias},
	{"unalias", we_unalias}
};
typedef struct alias {
	char *name;
	char *command;
	struct alias *next;
} alias;

alias *aliases = NULL;

int we_cd(char **args);
int we_env(char **args);
int we_help(char **args);
int we_echo(char **args);
int we_exit(char **args);
int we_alias(char **args);
void add_alias(const char *name, const char *command);
void display_aliases(void);
void remove_alias(const char *name);
int  we_unalias(char **args);
/* FUNCTION TO HANDLE PATH */

char *get_env(char *name, char **env);
int find_command(char *command, char **env, char *path_command);
void execute_command(char **av, char **env, char *path_command, char **argv);

/* SET AND UNSET ENV */
typedef
int _unsetenv(environ_t *envs, char *var);
int _setenv(environ_t *envs, char *var, char *val);
list_t *add_node(list_t **head, const char *str, int change_env);
int dlt_node_at_index(list_t **head, size_t ind);
char *starts(const char *str, const char *prefix);
size_t i_strlen(const char *str);
char *i_strcpy(char *dest, const char *src);
char *i_strcat(char *dest, const char *src);


#endif
