#include "shell.h"

void execute_input(char **argv)
{
    pid_t pid;
    int statuss;
    pid = fork();

    if (pid == -1)
    {
        exit(1);
    }
    if (pid == 0)
    {
        if (execve(argv[0], argv, NULL) == -1)
        {
            exit(2);
        }
        
    }else
    {
        wait(&statuss);
    }
    
    
    
}