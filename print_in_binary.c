#include "main.h"

/**
 * print_in_binary - Prints an unsigned int in binary
 * @list: va_list whose next argument is unsigned int
 * Return: The number of bytes printed
 */
int print_in_binary(va_list list)
{
	unsigned int byte = va_arg(list, unsigned int);
	unsigned int i;
	unsigned int size = sizeof(int) * 8;
	char to_be_printed[65];

	for (i = 1; i <= size; i++)
	{
		if ((byte & (1 << (size - i))))
			to_be_printed[i - 1] = '1';
		else
			to_be_printed[i - 1] = '0';
	}
	to_be_printed[i - 1] = '\0';
	i = 0;
	while (to_be_printed[i + 1])
	{
		if (to_be_printed[i] == '1')
			break;
		i++;
	}
	return (_printf("%s", to_be_printed + i));
}
