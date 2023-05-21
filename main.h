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

int we_cd (char **args);
int we_env (char **args);
int we_help (char **args);
int we_echo (char **args);
int we_exit (char **args);

/* FUNCTION TO HANDLE PATH */

char *get_env(char *name, char **env);
int find_command(char *command, char **env, char *path_command);
void execute_command(char **av, char **env, char *path_command, char **argv);

#endif
