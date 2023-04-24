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
	int written;
	char arg;
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		written = -1;
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case '%':
					written = write(1, format, 1);
					break;
				case 'c':
					arg = va_arg(list, int);
					written = write(1, &arg, 1);
					break;
				case 's':
					written = print_string(list);
					break;
				case '\0':
					if (bytes == 0)
						bytes = -1;
					break;
				default:
					written = write(1, format - 1, 2);
					break;
			}
		}
		else
		{
			written = write(1, format, 1);
		}
		if (written > 0)
			bytes += written;
		format++;
	}
	va_end(list);
	return (bytes);
}
