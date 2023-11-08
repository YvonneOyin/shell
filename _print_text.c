#include "shell.h"
/**
 * _print_text - the custom print function for the shell
 * @text: text to be printed
 */
void _print_text(const char *text) {
    write(STDOUT_FILENO, text, sizeof(text));
}