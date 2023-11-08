#include "shell.h"

int main(void)
{
    char *buffer = NULL;
    size_t buf_size = 0;
    ssize_t len;
    char *token;
    char **argv;
    int i = 0;
    while (1)
    {
        write(1, "$ ", 2);
        len = getline(&buffer, &buf_size, stdin);
        if(len == -1)
        {
            free(buffer);
            break;
        }
        token = strtok(buffer, " \t\n");
        argv = malloc (sizeof(char *) * 1024);

        while (token != NULL)
        {
            argv[i] = token;
            token = strtok(NULL, " \t\n");
            // write(1, argv[i], 30);
            i++;
        }
        argv[i] = NULL;

        for (int j = 0; j < i; j++)
        {
            printf("Token %d: %s\n", j, argv[j]);
        }

        free(argv);
        i = 0;
    }
        free(buffer);
    
    return (0);
}