#include "main.h"
#include "short_int_to_string.h"

/**
 * print_short - Prints a number
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_short(va_list list)
{
	char str[6];
	short int num;
	int bytes = -1;

	num = va_arg(list, int);
	short_to_string(num, str, 0);
	if (num < 0)
		bytes = _printf("%c%s", '-', str);
	else
		bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_unsigned_short - Prints an unsigned short in decimal
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_unsigned_short(va_list list)
{
	char str[6];
	unsigned short int num;
	int bytes = -1;

	num = va_arg(list, unsigned int);
	unsigned_short_to_string(num, str, 0);

	bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_short_octal - Prints an int in octal
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_short_octal(va_list list)
{
	char str[6];
	short int num;
	int bytes = -1;

	num = va_arg(list, int);
	short_to_string_octal(num, str);

	bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_short_hexadecimal_lower - Prints an unsigned short int
 * in hexadecimal (lowercase)
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_short_hexadecimal_lower(va_list list)
{
	char str[5];
	short int num;
	int bytes = -1;

	num = va_arg(list, int);
	short_to_string_hexadecimal(num, str, 'a');

	bytes = _printf("%s", str);
	return (bytes);
}

/**
 * print_short_hexadecimal_upper - Prints an unsigned short int
 * in hexadecimal (uppercase)
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */
int print_short_hexadecimal_upper(va_list list)
{
	char str[5];
	short int num;
	int bytes = -1;

	num = va_arg(list, unsigned int);
	short_to_string_hexadecimal(num, str, 'A');

	bytes = _printf("%s", str);
	return (bytes);
}
