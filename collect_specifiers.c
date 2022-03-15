#include "main.h"

/**
 * collect_specifiers - collect flags
 * @s: character to be evaluated
 * @pointer: pointer with flags structure
 * Return: 0 in case no finding, 1 in case any success
 */
int collect_specifiers(char s, flags *f)
{
	int finding = 1;
	switch (s)
	{
	case '+':
		f->mas = 1;
		break;
	case ' ':
		f->pound = 1;
		break;
	case '#':
		f->space = 1;
		break;
	default:
		finding = 0;
	}
	return (finding);
}
