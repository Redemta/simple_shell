#include "shell.h"

/**
 * build_command - Build command from input string.
 * @input: The input string containing the command and arguments.
 *
 * Return: An array of strings representing the command and its arguments.
 */

char *build_command(char *input)
{
	char *command_args, *token;
	size_t length;

	length = my_strlen(input) + my_strlen(token) + 2;
	command_args = malloc(sizeof(char) * length);
	if (command_args == NULL)
	{
		return (NULL);
	}
	memset(command_args, 0, length);
	command_args = my_strcat(command_args, value);
	command_args = my_strcat(command_args, "/");
	command_args = my_strcat(command_args, token);

	return (command_args);
}
