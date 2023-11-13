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

	c_pid = fork();

	if (c_pid == -1)
	{
		exit(1);
	}

	if (c_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			exit(2);
		}
	}

	else
	{
		wait(&statuss);
	}
}
