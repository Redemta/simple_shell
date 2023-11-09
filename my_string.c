#include "shell.h"

/**
 * my_strcpy - copy one string to another.
 * @dest: destination string.
 * @source: source string.
 *
 * Return: pointer to destination string.
 */

char *my_strcpy(char *dest, const char *source)
{
	int i;

	for (i = 0; source[i]; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * my_strcat - concatenate one string to another.
 * @dest: destination string.
 * @source: source string to concatenate.
 *
 * Return: pointer to the destination string.
 */

char *my_strcat(char *dest, char *source)
{
	int i;
	int dest_len = 0;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	for (i = 0; source[i] != '\0'; i++)
	{
		dest[dest_len + i] = source[i];
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * my_strdup - duplicate a string.
 * @str: string to duplicate.
 *
 * Return: pointer to duplicated tring, NULL on failure.
 */

char *my_strdup(char *str)
{
	size_t len = strlen(str);
	char *duplicate = (char *)malloc(len + 1);

	if (str == NULL)
	{
		return (NULL);
	}
	if (duplicate == NULL)
	{
		return (NULL);
	}
	strcpy(duplicate, str);
	return (duplicate);
}

/**
 * my_strchr - find first occurence of character in string.
 * @str: string to search.
 * @c: character to find.
 *
 * Return: pointer to char, NULL if not found.
 */

char *my_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}

/**
 * my_strncmp - compare first 'n' charcaters of two strings.
 * @str1: first strint to compare.
 * @str2: 2nd string to compare.
 * @n: max number of characters to compare.
 *
 * Return: 0 if equal, +ve if str1 is greater, -ve if str2 is greater
 */

int my_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && (*str1 || *str2))
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}
