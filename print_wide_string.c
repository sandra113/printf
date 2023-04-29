#include "main.h"
#include <wchar.h>

/**
 * print_wide_string - Prints a char pointer
 * @list: va_list whose next item is a wide string
 * Return: Number of bytes printed
 */

int print_wide_string(va_list list)
{
	wchar_t *str;
	int i;

	str = va_arg(list, wchar_t *);
	if (str == NULL)
	{
		str = (wchar_t *) "(null)";
	}
	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 32 && str[i] <= 127)
		{
			write(1, str, i);
		}
		else
		{
			_printf("\\x%02X", str[i]);
		}
	}
	return (i);
}
