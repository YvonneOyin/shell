#include "shell.h"

int main(void)
{
    char *buffer;
    char *argv[1024];
    int buf_len = _strlen(buffer), argg;
    while (true)
    {
        buffer = get_input();
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

        argg = parse_input(buffer, argv);
        if (argg > 0)
        {
            execute_input(argv);
        }
        

    }
    free(buffer);

    return (0);
}