#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	if (write(1, &c, 1) == -1)
	{
		return (-1);
	}
	return (1);
}

/**
 * _puts - prints an input string
 *
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _strlen - returns the length of a string
 *
 * @str: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

/**
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 *
 * @dest: pointer to the buffer in which we copy the string
 *
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int x, y = 0;

	x = 0;
	while (src[x] != '\0')
	{
		dest[y] = src[x];
		x++;
		y++;
	}
	dest[y] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings
 *
 * @s1: Pointer to a char[]
 * @s2: Pointer to a char[]
 *
 * Return: Integer value
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (0);
}
