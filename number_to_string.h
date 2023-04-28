#ifndef NUMBER_TO_STRING_UTIL_H
#define NUMBER_TO_STRING_UTIL_H

/*Utility functions to convert an int to a desired string*/

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
 * unsigned_int_to_string - converts an unsigned int value to string
 * @num: the integer to be converted
 * @str: the char pointer that stores the string
 * @depth: the length of the string
 * Return: the string
 */
int unsigned_int_to_string(unsigned int num, char *str, int depth)
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

	index = unsigned_int_to_string(num / 10, str, depth + 1);
	str[index] = num % 10 + '0';
	return (index + 1);
}

/**
 * number_to_string_octal - converts an int value to string in octal
 * @num: the integer to be converted
 * @str: the char pointer that stores the string
 * Return: the length of the string
 */
int number_to_string_octal(int num, char *str)
{
	int index = 0, n, i;

	n = ((num >> 30) & 3);
	if (n)
	{
		str[index] = n + '0';
		index++;
	}
	for (i = 27; i >= 0 && index == 0; i -= 3)
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
 * number_to_string_hexadecimal - converts an int value to string in hex
 * @num: the integer to be converted
 * @str: the char pointer that stores the string
 * @c: A character, either 'a' or 'A', for upper or lowercase
 * Return: the length of the string
 */
int number_to_string_hexadecimal(int num, char *str, char c)
{
	int index = 0, n, i;

	for (i = 28; i >= 0; i -= 4)
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
