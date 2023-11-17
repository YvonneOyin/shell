#include "shell.h"

int colon_separator(int num_commands, char **argv, char *buf)
{
	char *token;

	token = strtok(buf, ";");
	while (token != NULL)
	{
		argv[num_commands++] = token;
		token = strtok(NULL, ";");
	}
	return (num_commands);
}
