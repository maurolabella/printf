/**
 * print_char - print a character from _printf
 * @temp: va_list pointer from _printf
 * Returns: an integer in case of error
 */
int print_char(va_list temp)
{
	return (_putchar(va_arg(temp, int)));
}

/**
 * print_string - print a string from _printf
 * @temp: va_list pointer from _printf
 * Returns: an integer in case of error
 */
int print_string(va_list temp)
{
	char *s = va_arg(temp, char *);
	if (!s)
		s = "(null)";
	return (_puts(s));
}

/**
 * print number - print an integer looping its digits
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
 *counting_digits: count an integer digits
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
	return (i);
}

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
	do
	{
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
