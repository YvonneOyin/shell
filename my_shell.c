#include "shell.h"

/**
 * main - a simple shell function
 *
 * Return: 0 to indicate success
 */

void sigint_handler(int signo) {
    (void)signo;
    _print_text("\n");
    exit(0);
}
int main()
{
	char *buffer;
	char *argv[1024];
	/*char *path;*/
	int buf_len, argg;

    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }
	while (true)
	{
		buffer = get_inpt();
		if (buffer == NULL)
		{
			break;
		}
		buf_len = strlen(buffer);
		if (buf_len == 1)
		{
			free(buffer);
			continue;
		}

		argg = parse_inpt(buffer, argv);
		/*path = get_path(argv[0]);*/
		if (argg > 0)
		{
			execut_inpt(argv, environ);
		}
	        free (buffer);	
	}

	return (0);
}

