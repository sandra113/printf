#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_pointer - prints a pointer value
 * @list: - the va_list whose next argument is a pointer
 * Return: the value address
 */

int print_pointer(va_list list)
{
	int i;
	void *p;
	char buf[20];

	p = va_arg(list, void *);

	sprintf(buf, "%p", p);
	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] >= 'a' && buf[i] <= 'z')
		{
			buf[i] = buf[i] -  'a' + 'A';
		}
	}
	return (write(1, buf, i));
}
