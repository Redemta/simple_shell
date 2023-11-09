#include "shell.h"

/**
 * parse_input - parse a line of input.
 * @input: user input line.
 * Return: Number of characters parsed.
 */

char **parse_input(char *input)
{
	int num_arguments, buffsize = BUFSIZE;
	char *token;
	char **command;

	if (input == NULL)
		return (NULL);
	command = malloc(sizeof(char *) * buffsize);
	if (!command)
	{
		perror("hsh");
		return (NULL);
	}
	token = strtok(input, "\n ");
	for (num_arguments = 0; token; num_arguments++)
	{
		command[num_arguments] = strdup(token);
		token = strtok(NULL, "\n ");
	}
	command[num_arguments] = NULL;

	return (command);
}
