#include "shell.h"

/**
 * colon_separator - tokenize string by colon
 *
 * @num_commands: number of commands
 * @argv: array of delimeted commands
 * @buf: buffer to tokenize
 *
 * Return: returns no of commands
 */
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

/**
 * and_separator - tokenize string by colon
 *
 * @num_commands: number of commands
 * @argv: array of delimeted commands
 * @buf: buffer to tokenize
 *
 * Return: returns no of commands
 */
int and_separator(int num_commands, char **argv, char *buf)
{
	char *token;

	token = strtok(buf, "&&");
	while (token != NULL)
	{
		argv[num_commands++] = token;
		token = strtok(NULL, "&&");
	}
	return (num_commands);
}

/**
 * or_separator - tokenize string by colon
 *
 * @num_commands: number of commands
 * @argv: array of delimeted commands
 * @buf: buffer to tokenize
 *
 * Return: returns no of commands
 */
int or_separator(int num_commands, char **argv, char *buf)
{
	char *token;

	token = strtok(buf, "||");
	while (token != NULL)
	{
		argv[num_commands++] = token;
		token = strtok(NULL, "||");
	}
	return (num_commands);
}
