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
#include <signal.h>
#include <errno.h>
#include <ctype.h>

#define MAX_ARGS 1024

extern char **environ;

int _putchar(char);
void _print_text(char *);
char *get_inpt(void);
int parse_inpt(char *, char **);
char *get_path(char *);
void execut_inpt(char **, char **);
int get_built_in(char **);
char *get_full_path(char *, char *);
char *findpath();

/* string manipulation */
int _strlen(char *);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strchr(char *, char);

/*void prompt(__attribute__((unused))int);*/


#endif
