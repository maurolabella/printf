#include "main.h"

/**
 * fetch_function - pick the function
 * @s: character used to match
 * Return: NULL in case no match, a function otherwise
 */
int (*fetch_function(char s))(va_list)
{
	register short i;

	ph print_arr[] = {
		{'i', print_int},
		{'d', print_int},
		{'s', print_string},
		{'c', print_char},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexa},
		{'X', print_HEXA},
		{'p', print_address},
		{'S', print_bigs},
		{'b', print_binary},
		{'\0', '\0'}};

	for (i = 0; print_arr[i].c; i++)
		if (print_arr[i].c == s)
			return (print_arr[i].f);
	return (0);
}

/**
 * _printf - emulates printf
 * @format: formet string containing the characters and the specifiers
 * Return: length of the formatted output
 */
int _printf(const char *format, ...)
{
	int len = 0;
	int (*print_func)(va_list);
	va_list temp;
	const char *s = format;

	if (format == NULL)
		return (-1);

	va_start(temp, format);
	assert(wrong_inputs(s));

	while (*s != '\0')
	{
		if (*s == '%' && *(s + 1) != '\0')
		{
			switch (*++s)
			{
			case '%':
			{
				len += _putchar('%');
				break;
			}
			default:
			{
				print_func = fetch_function(*s);
				len += (print_func) ? print_func(temp) : _printf("%%%c", *s);
				break;
			}
			}
		}
		else
		{
			if (*s == '%')
				len = -1;
			else
				len += _putchar(*s);
		}
		s++;
	}
	_putchar(-1);
	va_end(temp);
	return (len);
}
