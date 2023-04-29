#include "main.h"

/**
 * print_wide_string - Prints a char pointer
 * @list: va_list whose next item is a wide string
 * Return: Number of bytes printed
 */

int print_wide_string(va_list list)
{
	wchar_t *str;
	int len;

	str = va_arg(list, wchar_t *);
	if (str == NULL)
	{
		str = "(null)";
	}
	len = strlen(str);
	return (write(1, str, len));
}
