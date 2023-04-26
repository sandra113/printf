#include "main.h"
#include "number_to_string.h"

/**
 * print_number - Prints a number
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_number(va_list list)
{
	char str[12];
	int num;
	int bytes = -1;

	num = va_arg(list, int);
	number_to_string(num, str, 0);
	if (num < 0)
		bytes = _printf("%c%s", '-', str);
	else
		bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_unsigned_int - Prints an unsigned int in decimal
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_unsigned_int(va_list list)
{
	char str[11];
	unsigned int num;
	int bytes = -1;

	num = va_arg(list, unsigned int);
	number_to_string(num, str, 0);

	bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_unsigned_octal - Prints an unsigned int in octal
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_unsigned_octal(va_list list)
{
	char str[12];
	unsigned int num;
	int bytes = -1;

	num = va_arg(list, unsigned int);
	number_to_string_octal(num, str);

	bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_hexadecimal_lower - Prints an unsigned int in hexadecimal (lowercase)
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_hexadecimal_lower(va_list list)
{
	char str[9];
	int num;
	int bytes = -1;

	num = va_arg(list, unsigned int);
	number_to_string_hexadecimal(num, str, 'a');

	bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_hexadecimal_upper - Prints an unsigned int in hexadecimal (uppercase)
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_hexadecimal_upper(va_list list)
{
	char str[9];
	int num;
	int bytes = -1;

	num = va_arg(list, unsigned int);
	number_to_string_hexadecimal(num, str, 'A');

	bytes = _printf("%s", str);
	return (bytes);
}

