#include "main.h"

/**
 * print_unsigned - prints an unsigned
 * @temp: va_list of _printf's arguments
 * @specs: flags descriptor if any
 * Return: number of char printed
 */
int print_unsigned(va_list temp, flags *specs)
{
	unsigned int t = va_arg(temp, unsigned int);
	char *str = convert(t, 10, 0);

	(void)specs;

	return (_puts(str));
}

/**
 * print_int - prints an integer
 * @temp: va_list of _printf's arguments
 * @specs: flags descriptor if any
 * Return: number of char printed
 */
int print_int(va_list temp, flags *specs)
{
	int n = va_arg(temp, int);
	int q = counting_digits(n);

	if (specs->space == 1 && specs->mas == 0 && n > 0)
		q += _putchar(' ');
	if (specs->mas == 1 && n > 0)
		q += _putchar('+');

	print_number(n);
	return (q);
}

/**
 * convert - converts a number (with its base) into a string
 * @num: the number
 * @base: the base
 * @lowercase: flag to signal if hex values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num);
	return (ptr);
}

/**
 * print_octal - prints an unsigned
 * @temp: va_list of _printf's arguments
 * @specs: pointer to flags
 * Return: number of char printed
 */
int print_octal(va_list temp, flags *specs)
{
	unsigned int t = va_arg(temp, unsigned int);
	char *str = convert(t, 8, 0);

	register short len = 0;

	if (specs->pound == 1 && *str != '0')
		len += _putchar('0');
	len += _puts(str);

	return (len);
}
