#include "main.h"
#include <stdlib.h>

/**
 * number_to_string - converts an int value to string
 * @num: the integer to be converted
 * @str: the char pointer that stores the string
 * @depth: the length of the string
 * Return: the string
 */

int number_to_string(unsigned long int num, char **str, int depth)
{
	int index, neg_index;

	if (num == 0 && depth > 0)
	{
		*str = malloc(sizeof(char) * (depth + 1));
		(*str)[depth] = '\0';
		return (0);
	}
	if (num == 0)
	{
		*str = malloc(sizeof(char) * (2));
		(*str)[1] = '\0';
		(*str)[0] = '0';
		return (1);
	}
	if (num < 0)
	{
		neg_index = number_to_string(-num, str, depth + 1);
		memmove(*str + 1, *str, neg_index);
		(*str)[0] = '-';
		return (neg_index + 1);
	}

	index = number_to_string(num / 10, str, depth + 1);
	(*str)[index] = num % 10 + '0';
	return (index + 1);
}
