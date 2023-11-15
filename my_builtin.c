#include "shell.h"

/**
 * handle_exit - exit shell
 * @command: parsed command
 * @value: user input
 * @argv: program name
 * @count: execute count
 *
 * Return: void
 */

void handle_exit(char **command, char *value, char **argv, int count)
{
	int i = 0, status;

	if (command[1] == NULL)
	{
		free(value);
		free(command);
		exit(EXIT_SUCCESS);
	}
	while (command[1][i])
	{
		if (my_isalpha(command[1][i++]) != 0)
		{
			_prerror(argv, count, command);
			break;
		}
		else
		{
			status = my_atoi(command[1]);
			free(value);
			free(command);
			exit(status);
		}
	}
}

/**
 * handle_change_dir - change directory
 * @command: parsed command;
 * @err: last command executed
 *
 * Return: 0 on success, 1 on failure
 */

int handle_change_dir(char **command, __attribute__((unused))int err)
{
	int input = -1;
	char cwd[PATH_MAX];

	if (command[1] == NULL)
	{
		input = chdir(getenv("HOME"));
	}
	else if (my_strcmp(command[1], "-") == 0)
	{
		input = chdir(getenv("OLDPWD"));
	}
	else
	{
		input = chdir(command[1]);
	}
	if (input == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (input != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * handle_help - display help
 * @command: parsed command
 * @err: last command executed
 *
 * Return: 0 on success, -1 on fail
 */

int handle_help(char **command, __attribute__((unused))int err)
{
	int file_d, write_f, read_f = 1;
	char ch;

	file_d = open(command[1], O_RDONLY);
	if (file_d < 0)
	{
		perror("Error");
		return (0);
	}
	while (read_f > 0)
	{
		read_f = read(file_d, &ch, 1);
		write_f = write(STDOUT_FILENO, &ch, read_f);
		if (write_f < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}

/**
 * handle_display_env - display environment variable
 *
 * Return: o always
 */

int handle_display_env(void)
{
	int length;
	size_t i = 0;

	while (environ[i] != NULL)
	{
		length = my_strlen(environ[i]);
		write(1, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
