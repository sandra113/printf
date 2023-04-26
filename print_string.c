#include "main.h"

/**
 * print_string - Prints a char pointer
 * @list: va_list whose next item is a string
 * Return: Number of bytes printed
 */
int print_string(va_list list)
{
	char *s;
	int size;

	s = va_arg(list, char *);
	if (s == NULL)
	{
		s = "(null)";
	}
	size = strlen(s);
	return (write(1, s, size));
}
