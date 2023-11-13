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

	c_pid = fork();
	path = get_path(argv[0]);

	if (c_pid == -1)
	{
		printf("fork failed");
		exit(1);
	}

	if (c_pid == 0)
	{
		printf("close to exec");
		if (execve(path, argv, env) == -1)
		{
			printf("exec error");
			exit(2);
		}
	}

	else
	{
		wait(&statuss);
	}
}
