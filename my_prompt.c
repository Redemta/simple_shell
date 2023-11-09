#include "shell.h"

/**
 * display_prompt - display shell prompt.
 *
 */

void display_prompt(void)
{
	my_printf("$ ");
}

/**
 * display_error - display error with loop count.
 * @err_message: The user input.
 * @loop_count: the count loop.
 * @argv: argument vector.
 *
 * Return: void.
 */

void display_error(char *err_message, int loop_count, char **argv)
{
	char err[12];

	my_printf("%s: ", argv[0]);
	sprintf(err, "%d", loop_count);
	my_printf("%s", err);
	my_printf(": ");
	my_printf("%s: Error\n", err_message);
}
