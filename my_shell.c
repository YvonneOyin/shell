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

void print_environment(char **env) {
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}

/**
 * main - Entry point
 *
 * Return: 0 to indicate success
 */
int main(void)
{
	char *buffer;
	char *argv[1024];
	/*char *path;*/
	int buf_len, argg, i, status;

	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		/*perror("signal");*/
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
			if (strcmp(argv[0], "env") == 0) {
                print_environment(environ);
                free(buffer);
                continue;
            }
			else if (strcmp(argv[0], "exit") == 0)
			{
				if (argv[1] == NULL)
        {
		free(buffer);
            exit(0);
        }
			
        else
        {
		for (i = 0; argv[1][i] != '\0'; i++)
            {
                if (!isdigit(argv[1][i]) && (i == 0 && argv[1][i] != '-'))
                {
			fprintf(stderr, "%s: %d: exit: Illegal number: %s\n", "./hsh", i+1, argv[1]);
                    exit(2);  
		}
            }
            status = atoi(argv[1]);
	    free (buffer);
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
			execut_inpt(argv, environ);
		}
		free(buffer);
	}
	return (0);
}
