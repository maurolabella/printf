#ifndef MYPROJECT
#define MYPROJECT

#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <stdbool.h>

#define ABS(x) (((x) < 0) ? -(x) : (x))

/**
 * struct handler - ph
 *
 * @c: The operator
 * @f: The function associated
 */
typedef struct handler
{
	char c;
	int (*f)(va_list temp);
} ph;

/**
 * struct flag_tree: to deal with modifiers
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

/*printing*/

int print_char(va_list temp);
int print_string(va_list temp);
void print_number(int n);
int counting_digits(int n);
int print_int(va_list temp);
int print_unsigned(va_list temp);
char *convert(unsigned long int num, int base, int lowercase);
int print_octal(va_list temp);
int print_hexa(va_list temp);
int print_HEXA(va_list temp);
int print_address(va_list temp);

/**control*/
int wrong_inputs(const char *p);

/*write*/
int _putchar(char c);
int _puts(char *str);

/*printf*/
int _printf(const char *format, ...);

/*fetching*/
int (*fetch_function(char c))(va_list);

#include "writing_functions.c"
#include "wrong_inputs.c"
#include "printing_functions.c"
#include "_printf.c"

#endif

