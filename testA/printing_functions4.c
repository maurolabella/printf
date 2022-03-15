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
