#include "shell.h"

/**
 * my_strcmp - Compare two strings.
 * @str1: first string to compare.
 * @str2: second string to compare.
 *
 * Return: 0 if equal, -ve if str1 < str2, +ve if str1 > str2
 */

int my_strcmp(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return (-1);
	}
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
		{
			return (*str1 - *str2);
		}
	}
	if (*str1 == '\0' && *str2 != '\0')
	{
		return (-1);
	}
	else if (*str1 != '\0' && *str2 == '\0')
	{
		return (1);
	}
	return (0);
}

/**
 * my_char_in_string - Checks If A Character Match Any Char in string.
 * @ch: character to check
 * @str: string to serach for  match.
 *
 * Return: 1 if match found, 0 if otherwise.
 */

int my_char_in_string(char ch, const char *str)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return (1);
		}
		str++;
	}
	return (0);
}

/**
 * my_strtok - tokenize a string into tokens.
 * @str: string to tokenize.
 * @del: set of delimiters.
 *
 * Return: pointer to next token, NULL if no more found.
 */

char *my_strtok(char *str, const char *del)
{
	static char *start_tok, *next_tok;
	unsigned int i;

	if (str != NULL)
		next_tok = str;
	start_tok = next_tok;
	if (start_tok == NULL)
		return (NULL);
	for (i = 0; start_tok[i] != '\0'; i++)
	{
		if (my_char_in_string(start_tok[i], del) == 0)
			break;
	}
	if (next_tok[i] == '\0' || next_tok[i] == '#')
	{
		next_tok = NULL;
		return (NULL);
	}
	start_tok = next_tok + i;
	next_tok = start_tok;
	for (i = 0; next_tok[i] != '\0'; i++)
	{
		if (my_char_in_string(next_tok[i], del) == 1)
			break;
	}
	if (next_tok[i] == '\0')
		next_tok = NULL;
	else
	{
		next_tok[i] = '\0';
		next_tok = next_tok + i + 1;
		if (*next_tok == '\0')
			next_tok = NULL;
	}
	return (start_tok);
}
