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
		s = "(null)";
	size = strlen(s);
	return (write(1, s, size));
}

/**
 * _printf - Produces output according to a format
 * @format: string containing format
 * Return: The number of bytes printed to fd 1
 */
int _printf(const char *format, ...)
{
	int bytes = 0;
	char arg;
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case '%':
					bytes += write(1, format, 1);
					break;
				case 'c':
					arg = va_arg(list, int);
					bytes += write(1, &arg, 1);
					break;
				case 's':
					bytes += print_string(list);
					break;
				default:
					break;
			}
		}
		else
		{
			write(1, format, 1);
			bytes++;
		}
		format++;
	}
	va_end(list);
	return (bytes);
}
