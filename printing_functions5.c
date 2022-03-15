#include"main.h"




/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @temp: va_list arguments from _printf
 * Return: number of char printed
 */
int print_bigs(va_list temp)
{
	register short len = 0;

	char *res, *s = va_arg(temp, char *);

	if (!s)
		return (_puts("(null)"));
	for (; *s; s++)
	{
		if (isNonAlphaNumeric(*s))
		{
			len += _puts("\\x");
			res = convert(*s, 16, 0);
			if (!res[1])
				len += _putchar('0');
			len += _puts(res);
		}
		else
			len += _putchar(*s);
	}
	return (len);
}

/**
 * isNonAlphaNumeric - determines if char is a non-
 * alphanumeric char on ASCII table
 * @c: input char
 * Return: true or false
 */
int isNonAlphaNumeric(char c)
{
	return ((c > 0 && c < 32) || c >= 127);
}

/**
 * print_rev - prints a string in reverse
 * @temp: argument from _printf
 * Return: length of the printed string
 */
int print_rev(va_list temp)
{
	register short len = 0, j;
	char *s = va_arg(temp, char *);

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
 * Return: length of the printed string
 */
int print_rot13(va_list temp)
{
	register short i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(temp, char *);

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
