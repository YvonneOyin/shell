#include "shell.h"

/**
 * execut_inpt - Execute shell commands entered by users
 *
 * @argv: vector array of pointers to the command and its arguments.
 *
 * Return: nothing
 */
void execut_inpt(char **argv, char **env)
{
	pid_t c_pid;
	int statuss;
	char *path;

	path = get_path(argv[0]);
	if (path == NULL)
	{
		if(get_built_in(argv) != 0)
			perror("Command not found");
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
			perror("Command not found\n");
			exit(2);
		}
	}

	else
	{
		wait(&statuss);
	}
}
