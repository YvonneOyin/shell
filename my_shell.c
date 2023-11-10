#include "shell.h"

/**
 * main - a simple shell function
 *
 * Return: 0 to indicate success
 */
int main(void)
{
	char *buffer;
	char *argv[1024];
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
		if (argg > 0)
		{
			execut_inpt(argv);
		}
	}
	free(buffer);

	return (0);
}
