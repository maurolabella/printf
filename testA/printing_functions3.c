#include "main.h"
/**
 * print_hexa - prints an unsigned hexadecimal
 * @temp: va_list of _printf's arguments
 * @specs: pointer to flags
 * Return: number of char printed
 */
int print_hexa(va_list temp, flags *specs)
{
	unsigned int t = va_arg(temp, unsigned int);
	char *str = convert(t, 16, 1);

	register short len = 0;

	if (specs->pound == 1 && *str != '0')
		len += _puts("0X");
	len += _puts(str);

	return (len);
}

/**
 * print_HEXA - prints an unsigned HEXADECIMAL
 * @temp: va_list of _printf's arguments
 * @specs: pointer to flags
 * Return: number of char printed
 */
int print_HEXA(va_list temp, flags *specs)
{
	unsigned int t = va_arg(temp, unsigned int);
	char *str = convert(t, 16, 0);

	register short len = 0;

	if (specs->pound == 1 && *str != '0')
		len += _puts("0X");
	len += _puts(str);

	return (len);
}

/**
 * print_address - print address in hexadecimal ?
 * @temp: va_list input
 * @specs: pointer to flags
 * Return: number of char printed
 */
int print_address(va_list temp, flags *specs)
{
	void *str;
	register int len = 0;

	unsigned long int n = va_arg(temp, unsigned long int);

	(void)specs;

	if (!n)
		return (_puts("(nil)"));
	str = (void *)convert(n, 16, 1);
	len = _puts("0x") + _puts(str);
	return (len);
}
