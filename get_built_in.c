#include "shell.h"

int get_built_in(char **argv){
	if (strcmp(argv[0], "exit") == 0)
	{
		_print_text("Exiting..\n");
		exit(0);
	}
	else if(strcmp(argv[0], "cd") == 0)
	{
		if(argv[1] == NULL)
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
