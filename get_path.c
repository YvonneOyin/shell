#include "shell.h"

/**
 * get_full_path - gets the path
 *
 * @path: a character pointer to the path
 * @arg:a character pointer to the argument
 *
 * Return: a string of characters
 */
char *get_full_path(char *path, char *arg)
{
	char *token;
	char *path_dup = strdup(path);
	char *full_path;

	token = strtok(path_dup, ":");
	full_path = malloc(strlen(arg) + strlen(token) + 2);
	while (token)
	{
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, arg);

		if (access(full_path, X_OK) == 0)
		{
			free(path_dup);
			return (full_path);
		}
		token = strtok(NULL, ":");
	}
	free(full_path);
	free(path_dup);

	return (NULL);
}

/**
 * get_path - gets the path
 *
 * @arg: character pointer to argument
 *
 * Return: a string of characters
 */
char *get_path(char *arg)
{
	char *path;
	char *new_path;

	path = getenv("PATH");
	if (path != NULL)
	{
		new_path = get_full_path(path, arg);
		if (new_path != NULL)
		{
			return (new_path);
		}

		new_path = get_full_path("/usr/", arg);
		if (new_path != NULL)
		{
			return (new_path);
		}
	}

	return (path);
}
