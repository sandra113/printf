#include "main.h"
#include <stdarg.h>

/**
 * _abs - Returns the absolute value of a number
 * @num: The number
 * Return: absolute value
 */
int _abs(int num)
{
	return (num >= 0 ? num : -num);
}
/**
 * number_to_string - converts an int value to string
 * @num: the integer to be converted
 * @str: the char pointer that stores the string
 * @depth: the length of the string
 * Return: the string
 */

int number_to_string(int num, char *str, int depth)
{
	int index;

	if (num == 0)
	{
		if (depth == 0)
		{
			str[1] = '\0';
			str[0] = '0';
			return (1);
		}
		str[depth] = '\0';
		return (0);
	}

	index = number_to_string(num / 10, str, depth + 1);
	str[index] = _abs(num % 10) + '0';
	return (index + 1);
}
/**
 * print_number - Prints a number
 * @list: va_list of arguments
 * Return: Number of bytes printed
 */

int print_number(va_list list)
{
	char str[11];
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

