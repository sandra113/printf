#include "main.h"

/**
 * evaluate_format - Prints variables according to specifier
 * @format: The format
 * @list: Argument list
 * Return: The number of bytes written
 */
int evaluate_format(const char *format, va_list list)
{
	int c;

	switch (*format)
	{
		case '%':
			return (write(1, format, 1));
		case 'c':
			c = va_arg(list, int);
			return (write(1, &c, 1));
		case 's':
			return (print_string(list));
		default:
			return (write(1, format - 1, 2));
	}
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

			if (bytes == 0 && *format == '\0')
				return (-1);
			written = evaluate_format(format, list);
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
