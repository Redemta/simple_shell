#include "shell.h"

/**
 * _readInput - Function to read input from stdin
 * Return: The input.
 */

char *_readInput()
{
	int index = 0;
	int buffsize = BUFSIZE;
	char *buff = malloc(buffsize);
	char c;

	if (buff == NULL)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}
	while ((c = getchar()) != EOF && c != '\n')
	{
		buff[index++] = c;

		if (index >= buffsize - 1)
		{
			buffsize *= 2;
			buff = realloc(buff, buffsize);
			if (buff == NULL)
			{
				perror("Reallocation error");
				exit(EXIT_FAILURE);
			}
		}
	}
	buff[index] = '\0';
	if (index == 0)
	{
		free(buff);
		return (strdup(""));
	}
	_hashtag(buff);
	return (buff);
}

/**
 * _hashtag - Remove everything after #
 * @input: The input.
 * Return: void
 */

void _hashtag(char *input)
{
	int i = 0;

	while (input[i] != '\0')
	{
		i++;

		if (input[i] == '#')
		{
			input[i] = '\0';
			break;
		}
	}
}
