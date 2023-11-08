#include "shell.h"

int parse_input(char *input, char **argv)
{
    int i = 0;
    char *token = strtok(input, " \t\n");

    while (token != NULL)
    {
        argv[i] = token;
        token = strtok(NULL, " \t\n");
        // write(1, argv[i], 30);
        i++;
    }
    argv[i] = NULL;

    return (i);
}

char *get_input()
{
    char *buffer = NULL;
    size_t buf_size = 0;
    ssize_t len;

    int buf_len;
    char *arr;

    _print_text("$ ");
    len = getline(&buffer, &buf_size, stdin);
    buf_len = _strlen(buffer);
    buffer[buf_len - 1] = "\0";
    if (len == -1)
    {
        free(buffer);
        return (NULL);
    }

    

    // for (int j = 0; j < i; j++)
    // {
    //     printf("Token %d: %s\n", j, argv[j]);
    // }
    
    return (buffer);
}