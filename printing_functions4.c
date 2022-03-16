#include "main.h"

/**
 * print_binary - prints a number in base 2
 * @temp: va_list arguments from _printf
 * @specs: pointer to flags
 * Return: the number of char printed
 */
int print_binary(va_list temp, flags *specs)
{
	unsigned int num = va_arg(temp, unsigned int);
	char *str = convert(num, 2, 0);

	(void)specs;

	return (_puts(str));
}

/**
 * print_rev - prints a string in reverse
 * @temp: argument from _printf
 * @specs: pointer to flags
 * Return: length of the printed string
 */
int print_rev(va_list temp,flags *specs)
{
	register short len = 0, j;
	char *s = va_arg(temp, char *);

	(void)specs;
	
	if (!s)
		s = "(null)";
	while (s[len])
		len++;
	for (j = len - 1; j >= 0; j--)
		_putchar(s[j]);
	return (len);
}

/**
 * print_rot13 - prints a string using rot13
 * @temp: list of arguments from _printf
 * @specs: pointer to flags
 * Return: length of the printed string
 */
int print_rot13(va_list temp, flags *specs)
{
	register short i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(temp, char *);

	(void)specs;

	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);
		else
		{
			for (i = 0; i <= 52; i++)
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
		}
	}
	return (j);
}
