#include "shell.h"

/**
 * parse_inpt - parses user's input
 *
 * @inpt: a pointer to a string
 * @argv: a char array of pointers
 *
 * Return: nothing
 */
int parse_inpt(char *inpt, char **argv)
{
	int i = 0;
	char *token = strtok(inpt, " \t\n");

	while (token != NULL)
	{
		if (i < MAX_ARGS - 1)
		{
			argv[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
	}
	argv[i] = NULL;

	return (i);
}

/**
 * get_inpt - Displays the shell to prompt users for input
 *
 * Return: buffer
 */
char *get_inpt(void)
{
	char *buffer = NULL;
	size_t buf_size = 0;
	ssize_t len;
	int buf_len;

	_print_text("$ ");
	len = getline(&buffer, &buf_size, stdin);
	buf_len = _strlen(buffer);
	buffer[buf_len - 1] = '\0';
	if (len == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (len == 1)
	{
		free(buffer);
		return (NULL);
	}

	return (buffer);
}
