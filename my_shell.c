#include "shell.h"

/**
 * sigint_handler - handles the sign in
 *
 * @signo: an integer type
 *
 * Return: void which is nothing
 */
void sigint_handler(int signo)
{
	(void)signo;
	exit(0);
}

/**
 * main - Entry point
 *
 * Return: 0 to indicate success
 */
int main(void)
{
	char *buffer, *command, *argvv[1024];
	char *argv[1024];
	int buf_len, i, argg, num_commands = 0;

	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		exit(EXIT_FAILURE);
	}
	while (true)
	{
		num_commands = 0;
		buffer = get_inpt();
		if (buffer == NULL)
		{
			break;
		}
		num_commands = colon_separator(num_commands, argv, buffer);
		buf_len = strlen(buffer);
		if (buf_len == 1)
		{
			free(buffer);
			continue;
		}
		for (i = 0; i < num_commands; ++i)
		{
			command = argv[i];

			argg = parse_inpt(command, argvv);
			if (argg > 0)
			{
				execut_inpt(argvv, environ);
			}
		}
		free(buffer);
	}
	return (0);
}
