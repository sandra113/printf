#ifndef LONG_TO_STRING_UTIL_H
#define LONG_TO_STRING_UTIL_H

/*Utility functions to convert a long int to a desired string*/

/**
 * long_abs - Returns the absolute value of a number
 * @num: The number
 * Return: absolute value
 */
long int long_abs(long int num)
{
	return (num >= 0 ? num : -num);
}

/**
 * long_to_string - converts an int value to string
 * @num: the long integer to be converted
 * @str: the char pointer that stores the string
 * @depth: the length of the string
 * Return: the string
 */

int long_to_string(long int num, char *str, int depth)
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

	index = long_to_string(num / 10, str, depth + 1);
	str[index] = long_abs(num % 10) + '0';
	return (index + 1);
}

/**
 * unsigned_long_to_string - converts an unsigned long value to string
 * @num: the long integer to be converted
 * @str: the char pointer that stores the string
 * @depth: the length of the string
 * Return: the string
 */
int unsigned_long_to_string(unsigned long int num, char *str, int depth)
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

	index = unsigned_long_to_string(num / 10, str, depth + 1);
	str[index] = num % 10 + '0';
	return (index + 1);
}

/**
 * long_to_string_octal - converts long int value to string in octal
 * @num: the long integer to be converted
 * @str: the char pointer that stores the string
 * Return: the length of the string
 */
int long_to_string_octal(long int num, char *str)
{
	int index = 0, i;
	long int n;

	n = ((num >> 63) & 1);
	if (n)
	{
		str[index] = n + '0';
		index++;
	}
	for (i = 60; i >= 0 && index == 0; i -= 3)
	{
		n = ((num >> i) & 7);
		if (n)
			break;
	}
	do {
		n = ((num >> i) & 7);
		str[index] = n + '0';
		index++;
		i -= 3;
	} while (i >= 0);
	str[index] = '\0';
	return (index);
}

/**
 * long_to_string_hexadecimal - converts a long int value
 * to string in hexadecimal
 * @num: the long integer to be converted
 * @str: the char pointer that stores the string
 * @c: A character, either 'a' or 'A', for upper or lowercase
 * Return: the length of the string
 */
int long_to_string_hexadecimal(long int num, char *str, char c)
{
	int index = 0, i;
	long int n;

	for (i = 60; i >= 0; i -= 4)
	{
		n = ((num >> i) & 15);
		if (n)
			break;
	}
	do {
		n = ((num >> i) & 15);
		if (n < 10)
			str[index] = n + '0';
		else
			str[index] = (n % 10) + c;
		index++;
		i -= 4;
	} while (i >= 0);
	str[index] = '\0';
	return (index);
}


#endif
