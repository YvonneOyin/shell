#include "shell.h"

/**
 * execut_inpt - Execute shell commands entered by users
 *
 * @argv: vector array of pointers to the command and its arguments.
 * @env: environment
 *
 * Return: nothing
 */
int execut_inpt(char **argv, char **env)
{
	pid_t c_pid;
	int statuss;
	char *path;

	path = get_path(argv[0]);
	if (path == NULL)
	{
		if (get_built_in(argv) != 0)
		{
			fprintf(stderr, "hsh: 1: %s: Command not found\n", argv[0]);
			exit(2);
		}
	}

	c_pid = fork();
	if (c_pid == -1)
	{
		printf("fork failed");
		exit(1);
	}

	if (c_pid == 0)
	{

		if (execve(path, argv, env) == -1)
		{
			fprintf(stderr, "hsh: 1: %s: Command not found\n", argv[0]);
			exit(2);
		}
	}

	else
	{
		wait(&statuss);
		free(path);
		return (WEXITSTATUS(statuss));
	}
	free(path);
	return (0);
}
