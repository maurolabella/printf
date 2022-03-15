#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character c to stdout
 *  @c: the character
 * Return: On success 1
 * On error, -1 is returned.
 * Description: _putchar uses a local buffer of 1024 to call write
 * as little as possible.
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int i;

	if (c == -1)
	{
		write(1, &buffer, i);
		i = 0;
	}
	else if (i >= 1024)
	{
		write(1, &buffer, i);
		buffer[0] = c;
		i = 1;
	}
	else
	{
		buffer[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - writes a string c to stdout
 *  @str: the string
 * Return: number of characters printed
 */
int _puts(char *str)
{
	register short i;

	for (i = 0; str[i]; i++)
		_putchar(str[i]);
	return (i);
}
