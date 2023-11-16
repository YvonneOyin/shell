#include "shell.h"

/**
 * get_full_path - gets the path
 *
 * @ppath: a character pointer to the path
 * @arg:a character pointer to the argument
 *
 * Return: a string of characters
 */
char *get_full_path(char *ppath, char *arg)
{
	char *token;
	char *path_dup = strdup(ppath);
	char *full_path;

	token = strtok(path_dup, ":");
	/*full_path = malloc(strlen(arg) + strlen(token) + 2);*/
	while (token)
	{
		full_path = malloc(strlen(arg) + strlen(token) + 2);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, arg);
		strcat(full_path, "\0");

		if (access(full_path, X_OK) == 0)
		{
			free(path_dup);
			return (full_path);
		}
		token = strtok(NULL, ":");
		free(full_path);
	}
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
	char *paath;
	char *new_path;

	paath = getenv("PATH");
	if (paath != NULL)
	{
		new_path = get_full_path(paath, arg);
		if (new_path != NULL)
		{
			return (new_path);
		}

		new_path = get_full_path("/usr/local/sbin:/usr/local/:/usr/sbin:/usr/:/sbin:/", arg);
		if (new_path != NULL)
		{
			return (new_path);
		}
	}
	return (NULL);
}
