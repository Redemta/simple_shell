#include "shell.h"

/**
 * build_command - Build command from input string.
 * @input: The input string containing the command and arguments.
 *
 * Return: An array of strings representing the command and its arguments.
 */

char *build_command(char *input, char *token)
{
	char *command_args;
	size_t length;

	length = my_strlen(input) + my_strlen(token) + 2;
	command_args = malloc(sizeof(char) * length);
	if (command_args == NULL)
	{
		return (NULL);
	}
	memset(command_args, 0, length);
	command_args = my_strcat(command_args, input);
	command_args = my_strcat(command_args, "/");
	command_args = my_strcat(command_args, token);

	return (command_args);
}

/**
 * search_command - serach in $MY_PATH for an executable command.
 * @command: The command to search for.
 *
 * Return: 1 on failure, 0 on succes.
 */

int search_command(char **command)
{
	char *path = my_getenv_value("MY_PATH");
	char *token, *full_path;
	struct stat buf;
	int found = 0;

	if (path == NULL || *command == NULL)
	{
		return (1);
	}

	token = my_strtok(path, ":");

	while (token != NULL && !found)
	{
		full_path = build_command(*command, token);
		if (full_path != NULL && stat(full_path, &buf) == 0)
		{
			*command = my_strdup(full_path);
			found = 1;
		}
		free(full_path);
		token = my_strtok(NULL, ":");
	}
	free(path);
	return (found ? 0 : 1);
}
