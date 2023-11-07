#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/types.h>

extern char **environ;

int _putchar(char);
void _puts(char *);

/* string manipulation */
int _strlen(char *);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);
char *_strcat(char *, char *);
char *_strchr(char *, char);

void prompt(__attribute__((unused))int);


#endif /* _SHELL_H_ */
