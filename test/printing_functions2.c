#include "main.h"

/**
 * print_unsigned - prints an unsigned
 * @temp: va_list of _printf's arguments
 * Return: number of char printed
 */
int print_unsigned(va_list temp)
{
	unsigned int t = va_arg(temp, unsigned int);
	char *str = convert(t, 10, 0);

	return (_puts(str));
}

/**
 * print_int - prints an integer
 * @temp: va_list of _printf's arguments
 * Return: number of char printed
 */
int print_int(va_list temp)
{
	int n = va_arg(temp, int);
	int q = counting_digits(n);

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
 * Return: number of char printed
 */
int print_octal(va_list temp)
{
	unsigned int t = va_arg(temp, unsigned int);
	char *str = convert(t, 8, 0);

	return (_puts(str));
}
