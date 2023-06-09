#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#define TOKEN_BUFFSIZE 64

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

/**  FUNCTIONS PROTOTYPES */

void print_rev(char *s);
void get_prompt(char **av, char **env);
void tokenize_input(char *str, char **argv, int max_args);
void _prompt(char **av, char **env);
void free_argv(char **argv);
void execute_commands(char **env, char *path_command, char **argv);

/* EXECUTION */
void child_process(char **av, char **env, char *path_command, char **argv);
void parent_process(pid_t pid, int status, char **argv);


/** Printing Strings **/
void _puts(char **strg);

/** Built in Functions **/
int main(int argc, char *argv[], char *envp[]);

/* FUNCTION TO HANDLE PATH */

char *get_env(char *name, char **env);
int find_command(char *command, char **env, char *path_command);
void execute_command(char **av, char **env, char *path_command, char **argv);

/* SET AND UNSET ENV */

typedef struct list_t
{
	char *str;
	int change_env;
	int data;
	struct list_t *next;
} list_t;

typedef struct environ_s
{
	list_t *env;
	int change_env;
	int argc;
	char **argv;
	char **envp;
	char **alias;
	char **history;
} environ_t;

/* ALIASES */

/*Defining the alias data structure */
typedef struct alias {
	char *name;
	char *value;
	struct alias *next;
} alias_t;


/* Defining info_t data structure */

typedef struct {
	int argc;
	char **argv;
	alias_t *alias;
} info_t;

/* Function Prototypes for Aliases */
alias_t *node_starts_with(alias_t *alias, const char *name, char delimiter);
int printAlias(alias_t *aliasNode);
int alias(info_t *infoT);
alias_t *makeAlias(const char *name, const char *value);
void freeAlias(alias_t *alias);

/* Alias */
typedef struct node {
    char *str;
    struct node *next;
} node_t;


int _unsetenv(environ_t *envs, char *var);
int _setenv(environ_t *envs, char *var, char *val);
list_t *add_node(list_t **head, const char *str, int change_env);
int dlt_node_at_ind(list_t **head, size_t ind);
char *starts(const char *str, const char *prefix);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);


#endif
