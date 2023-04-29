#include "main.h"

/**
 * evaluate_long_format - Prints variables according to specifier
 * @format: The format, the previous specifier was 'h'
 * @list: Argument list
 * Return: The number of bytes written
 */
int evaluate_long_format(const char **format, va_list list)
{
	switch (**format)
	{
		case 'd':
		case 'i':
			return (print_long(list));
		case 'u':
			return (print_unsigned_long(list));
		case 'o':
			return (print_long_octal(list));
		case 'x':
			return (print_long_hexadecimal_lower(list));
		case 'X':
			return (print_long_hexadecimal_upper(list));
		default:
			return (write(1, *format - 2, 3));
	}
}

/**
 * evaluate_short_format - Prints variables according to specifier
 * @format: The format, the previous specifier was 'h'
 * @list: Argument list
 * Return: The number of bytes written
 */
int evaluate_short_format(const char **format, va_list list)
{
	switch (**format)
	{
		case 'd':
		case 'i':
			return (print_short(list));
		case 'u':
			return (print_unsigned_short(list));
		case 'o':
			return (print_short_octal(list));
		case 'x':
			return (print_short_hexadecimal_lower(list));
		case 'X':
			return (print_short_hexadecimal_upper(list));
		default:
			return (write(1, *format - 2, 3));
	}
}

/**
 * evaluate_format - Prints variables according to specifier
 * @format: The format
 * @list: Argument list
 * Return: The number of bytes written
 */
int evaluate_format(const char **format, va_list list)
{
	int c;

	switch (**format)
	{
		case '%':
			return (write(1, *format, 1));
		case 'c':
			c = va_arg(list, int);
			return (write(1, &c, 1));
		case 's':
			return (print_string(list));
		case 'd':
		case 'i':
			return (print_number(list));
		case 'b':
			return (print_in_binary(list));
		case 'u':
			return (print_unsigned_int(list));
		case 'o':
			return (print_unsigned_octal(list));
		case 'x':
			return (print_hexadecimal_lower(list));
		case 'X':
			return (print_hexadecimal_upper(list));
		case 'h':
			++(*format);
			return (evaluate_short_format(format, list));
		case 'l':
			++(*format);
			return (evaluate_long_format(format, list));
		default:
			return (write(1, *format - 1, 2));
	}
}

/**
 * _printf - Produces output according to a format
 * @format: String containing format
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
			written = evaluate_format(&format, list);
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
