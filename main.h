#ifndef MYPROJECT
#define MYPROJECT

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define ABS(x) (((x) < 0) ? -(x) : (x))

/**
 * struct flag_tree - to deal with modifiers
 * had to include stdbool
 * @mas: flag for the + symbol
 * @space: flag for the space symbol
 * @pound: flag for the pound symbol
 */
typedef struct flag_tree
{
	int mas;
	int space;
	int pound;
} flags;

/**
 * struct handler - ph
 *
 * @c: The operator
 * @f: The function associated
 */
typedef struct handler
{
	char c;
	int (*f)(va_list temp, flags *s);
} ph;


/*printing*/

int print_char(va_list temp, flags *specs);
int print_string(va_list temp, flags *specs);
void print_number(int n);
int counting_digits(int n);
int print_int(va_list temp, flags *specs);
int print_unsigned(va_list temp, flags *specs);
char *convert(unsigned long int num, int base, int lowercase);
int print_octal(va_list temp, flags *specs);
int print_hexa(va_list temp, flags *specs);
int print_HEXA(va_list temp, flags *specs);
int print_address(va_list temp, flags *specs);
int print_binary(va_list temp, flags *specs);
int print_bigS(va_list temp, flags *specs);
int isNonAlphaNumeric(char c);
int print_rev(va_list temp, flags *specs);

/**control*/
int wrong_inputs(const char *p);
int collect_specifiers(char s, flags *f);

/*write*/
int _putchar(char c);
int _puts(char *str);

/*printf*/
int _printf(const char *format, ...);

/*fetching*/
int (*fetch_function(char c))(va_list, flags *);

#endif
