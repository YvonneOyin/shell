#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int _putchar(char);
void _print_text(char *str);
char *get_input();
int parse_input(char *input, char **argv);
void execute_input(char **argv);

/* string manipulation */
int _strlen(char *);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strchr(char *, char);

// void prompt(__attribute__((unused))int);


#endif 
