#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/**  FUNCTIONS PROTOTYPES */
void print_rev(char *s);
void get_prompt(char **av, char **env);

#endif
