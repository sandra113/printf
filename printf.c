#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: string containing format
 * Return: The number of bytes printed to fd 1
 */
int _printf(const char *format, ...)
{
	int bytes = 0;
	int size;
	char arg;
	char *s;
	va_list list;

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
					s = va_arg(list, char*);
					size = strlen(s);
					bytes += write(1, s, size);
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
