#include "shell.h"

/**
 * my_isalpha - check is character is alphabetic.
 * @c: The character to check.
 *
 * Return: 1 if true, 0 if false.
 */

int my_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * my_arrayrev - Reverse an array of charcaters.
 * @arr: array to reverse.
 * @length: length of the array.
 */

void my_arrayrev(char arr[], int length)
{
	int start = 0;
	int end = length - 1;
	char tmp;

	while (start < end)
	{
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
}

/**
 * my_intlen - calculate length of an integer.
 * @num: integer to find the length of.
 *
 * Return: length of the integer.
 */

int my_intlen(unsigned int num)
{
	int length = 0;

	if (num == 0)
	{
		return (1);
	}
	while (num != 0)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

/**
 * my_itoa - convert integer to character array.
 * @num: integer to convert.
 *
 * Return: converted character.
 */

char *my_itoa(unsigned int num)
{
	char *str;
	int i = 0, index = 0;

	index = my_intlen(num);
	str = malloc(index + 1);
	if (!str)
		return (NULL);
	*str = '\0';
	while (num / 10)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i++;
	}
	str[i] = (num % 10) + '0';
	my_arrayrev(str, index);
	str[i + 1] = '\0';
	return (str);
}
