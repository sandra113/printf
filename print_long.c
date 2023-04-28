#include "main.h"
#include "long_int_to_string.h"

/**
 * print_long - Prints a number
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_long(va_list list)
{
	char str[20];
	long int num;
	int bytes = -1;

	num = va_arg(list, long int);
	long_to_string(num, str, 0);
	if (num < 0)
		bytes = _printf("%c%s", '-', str);
	else
		bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_unsigned_long - Prints an unsigned long in decimal
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_unsigned_long(va_list list)
{
	char str[21];
	unsigned long int num;
	int bytes = -1;

	num = va_arg(list, unsigned long int);
	unsigned_long_to_string(num, str, 0);

	bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_long_octal - Prints an int in octal
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_long_octal(va_list list)
{
	char str[23];
	long int num;
	int bytes = -1;

	num = va_arg(list, long int);
	long_to_string_octal(num, str);

	bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_long_hexadecimal_lower - Prints an unsigned long int
 * in hexadecimal (lowercase)
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_long_hexadecimal_lower(va_list list)
{
	char str[17];
	long int num;
	int bytes = -1;

	num = va_arg(list, long int);
	long_to_string_hexadecimal(num, str, 'a');

	bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_long_hexadecimal_upper - Prints an unsigned long int
 * in hexadecimal (uppercase)
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_long_hexadecimal_upper(va_list list)
{
	char str[17];
	long int num;
	int bytes = -1;

	num = va_arg(list, unsigned long int);
	long_to_string_hexadecimal(num, str, 'A');

	bytes = _printf("%s", str);
	return (bytes);
}
