#include "shell.h"
/**
 * print_environment - prints the environment path like printenv
 *
 * @env: environment variable
 *
 * Return: nothing
 */
void print_environment(char **env)
{
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * get_built_in - it executes built in commands
 *
 * @argv: an array of character pointers
 *
 * Return: 0 to indicate success
 */
int get_built_in(char **argv)
{
	int i, status;

	if (strcmp(argv[0], "env") == 0)
	{
		print_environment(environ);
	}
	else if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] == NULL)
		{
			exit(0);
		}
		else
		{
			for (i = 0; argv[1][i] != '\0'; i++)
			{
				if (!isdigit(argv[1][i]) && (i == 0 && argv[1][i] != '-'))
				{
					fprintf(stderr, "error");
					exit(2);
				}
			}
			status = atoi(argv[1]);
			exit(status);
		}
	}

	else if (strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL)
		{
			chdir(getenv("HOME"));
		}
		else
		{
			chdir(argv[1]);
		}
	}
	return (0);
}
