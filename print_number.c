#include "main.h"
#include <stdlib.h>

/**
 * print_number - prints a number
 * @list: va_list whose next item is a number
 * Return: Number of bytes printed
 */

int print_number(va_list list)
{
	int i;
	char *number, *num;

	num = va_arg(list, char*);
	i = 0; 
	if (num[i] != '\0')
	{
		i++;
	}
	number = malloc(sizeof(char) * i + 1);
	if (!number)
		return (1);

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] < '0' || num[i] > '9')
			return (1);
		number[i] = num[i] + '0';
	}
	number[i] = '\0';

	return (write (1, number, i));
}
