#include "shell.h"

/**
 * main - a simple shell function
 *
 * Return: 0 to indicate success
 */
int main(int c, char *argvv, char *env)
{
	char *buffer;
	char *argv[1024];
    char *path;
	int buf_len = _strlen(buffer), argg;

	while (true)
	{
		buffer = get_inpt();
		if (buffer == NULL)
		{
			_print_text("\n");
			break;
		}
		if (buf_len == 0)
		{
			free(buffer);
			continue;
		}

		argg = parse_inpt(buffer, argv);
        path = get_path(argv[0]);
		if (argg > 0)
		{
			execut_inpt(argv, env);
		}
	}
	free(buffer);

	return (0);
}
