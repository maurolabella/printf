#include "main.h"

/**
 * print_char - print a character from _printf
 * @temp: va_list pointer from _printf
 * Return: an integer in case of error
 */
int print_char(va_list temp)
{		
	return (_putchar(va_arg(temp, int)));
}

/**
 * print_string - print a string from _printf
 * @temp: va_list pointer from _printf
 * Return: an integer in case of error
 */
int print_string(va_list temp)
{
	char *s = va_arg(temp, char *);

	if (s == NULL)
		s = "(null)";
	return (_puts(s));
}

/**
 * print_number - print an integer looping its digits
 * @n: integer received
 */
void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
		_putchar('-');
	n1 = ABS(n);
	if (n1 / 10)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * counting_digits - count an integer digits
 *  @n: received integer
 * Return: number of digits
 */
int counting_digits(int n)
{
	unsigned int i = 0;
	unsigned int d = ABS(n);

	while (d)
	{
		d /= 10;
		i++;
	}
	if ((i == 0 && n == 0) || (n < 0))
		i++;
	return (i);
}

