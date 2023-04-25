#include "main.h"
#include <stdlib.h>

/**
 * print_number - prints a number
 * @list: va_list whose next item is a number
 * Return: Number of bytes printed
 */

int number_to_string(int num, char **str, int depth)
{
	int index;
	
	if (num == 0)
	{
		if (depth == 0)
		{
			*str = malloc(sizeof(char) * (2));
			(*str)[1] = '\0';
			(*str)[0] = '0';
			return 1;
		}
		*str = malloc(sizeof(char) * (depth +1));
		(*str)[depth] = '\0';
		return 0;
	}
	index = number_to_string(num / 10, str, depth + 1);
	(*str)[index] = num % 10 + '0';
	return index + 1;
}
