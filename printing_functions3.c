#include "main.h"
/**
 * print_hexa - prints an unsigned hexadecimal
 * @temp: va_list of _printf's arguments
 * Return: number of char printed
 */
int print_hexa(va_list temp)
{
	unsigned int t = va_arg(temp, unsigned int);
	char *str = convert(t, 16, 1);

	return (_puts(str));
}

/**
 * print_HEXA - prints an unsigned HEXADECIMAL
 * @temp: va_list of _printf's arguments
 * Return: number of char printed
 */
int print_HEXA(va_list temp)
{
	unsigned int t = va_arg(temp, unsigned int);
	char *str = convert(t, 16, 0);

	return (_puts(str));
}

/**
 *  print_address - print address in hexadecimal ?
 * @temp: va_list input
 * @param temp
 * Return: number of char printed
 */
int print_address(va_list temp)
{
	void *str;
	unsigned long int n = va_arg(temp, unsigned long int);

	register int len = 0;

	if (!n)
		return (_puts("(nil)"));
	str = (void *)convert(n, 16, 1);
	len = _puts("0x7ffe") + _puts(str);
	return (len);
}
