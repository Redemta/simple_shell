#include "shell.h"

/**
 * my_strncpy - copy the first and characters of  astring.
 * @dest: destination string.
 * @src: source string.
 * @n: num of characters.
 *
 * Return: destination string.
 */

char *my_strncpy(char *dest, const char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * my_strlen - find length of a string.
 * @str: The string
 * Return: Total no of characters counted.
 */

size_t my_strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * my_atoi - convert string to integer.
 * @str: The string to convert.
 *
 * Return: converted integer.
 */

int my_atoi(const char *str)
{
	int r = 0;
	int s = 1;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		s = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return (s * r);
}

/**
 * my_puts - print a string.
 * @str: The string to print.
 */

void my_puts(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		my_printf("%c\n", str[i]);
		i++;
	}
}
