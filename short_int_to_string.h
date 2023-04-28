#ifndef SHORT_TO_STRING_UTIL_H
#define SHORT_TO_STRING_UTIL_H

/*Utility functions to convert a short int to a desired string*/

/**
 * short_abs - Returns the absolute value of a number
 * @num: The number
 * Return: absolute value
 */
short int short_abs(short int num)
{
	return (num >= 0 ? num : -num);
}

/**
 * short_to_string - converts an int value to string
 * @num: the short integer to be converted
 * @str: the char pointer that stores the string
 * @depth: the length of the string
 * Return: the string
 */

int short_to_string(short int num, char *str, int depth)
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

	index = short_to_string(num / 10, str, depth + 1);
	str[index] = short_abs(num % 10) + '0';
	return (index + 1);
}

/**
 * unsigned_short_to_string - converts an unsigned short value to string
 * @num: the short integer to be converted
 * @str: the char pointer that stores the string
 * @depth: the length of the string
 * Return: the string
 */
int unsigned_short_to_string(unsigned short int num, char *str, int depth)
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

	index = unsigned_short_to_string(num / 10, str, depth + 1);
	str[index] = num % 10 + '0';
	return (index + 1);
}

/**
 * short_to_string_octal - converts short int value to string in octal
 * @num: the short integer to be converted
 * @str: the char pointer that stores the string
 * Return: the length of the string
 */
int short_to_string_octal(short int num, char *str)
{
	int index = 0, i;
	short int n;

	n = ((num >> 15) & 1);
	if (n)
	{
		str[index] = n + '0';
		index++;
	}
	for (i = 12; i >= 0 && index == 0; i -= 3)
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
 * short_to_string_hexadecimal - converts a short int value
 * to string in hexadecimal
 * @num: the short integer to be converted
 * @str: the char pointer that stores the string
 * @c: A character, either 'a' or 'A', for upper or lowercase
 * Return: the length of the string
 */
int short_to_string_hexadecimal(short int num, char *str, char c)
{
	int index = 0, i;
	short int n;

	for (i = 12; i >= 0; i -= 4)
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
