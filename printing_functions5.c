#include "main.h"

/**
 * print_bigS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @temp: va_list arguments from _printf
 * Return: number of char printed
 */
int print_bigS(va_list temp)
{
	register short len = 0;
	
	char *res, *s = va_arg(temp, char *);
	
	if (!s)
		return (_puts("(nil)"));
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
