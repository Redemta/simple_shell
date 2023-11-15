#include "shell.h"

/**
 * main - hsh
 * @argc: argument count
 * @argv: argument vector
 * Return: Exit status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *value, **command;
	int i = 0, status = 1;

	while (status)
	{
		i++;
		if (isatty(STDIN_FILENO))
			display_prompt();
		value = _readInput();
		if (value[0] == '\0')
		{
			continue;
		}
		my_history(value);
		command = parse_input(value);
		if (my_strcmp(command[0], "exit") == 0)
		{
			handle_exit(command, value, argv, i);
		}
		my_free_array(command, value);
	}
	return (status);
}
