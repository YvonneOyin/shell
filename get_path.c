#include "shell.h"

char *get_full_path(char *path, char *arg)
{
    char *token;
    char *path_dup = strdup(path);
    char *full_path;
    token = strtok(path_dup, ":");
    full_path = malloc(strlen(arg) + strlen(token) + 2);
    while (token)
    {
        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, arg);
        strcat(full_path, "\0");

        if (access(full_path, F_OK) == 0)
        {
            /*memory leak here*/
            return (full_path);
        }
        token = strtok(NULL, ":");
        
    }
    free(path_dup);
    free(full_path);

    return (full_path);
    
}

char *get_path(char *arg)
{
    char *path;

    path = getenv("PATH");

    if (path != NULL)
    {
        path = get_full_path(path, arg);
        return (path);
    }
    return (path);
}
