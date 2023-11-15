#include "shell.h"

/**
 * my_history - fill file by user input
 * @inp: the user input
 *
 * Return: 1 on failure, 0 on success
 */

int my_history(char *inp)
{
	ssize_t w;
	char *filename = "my_simple_shell_history";
	int length = 0, file_d;

	if (!filename || filename[0] == '\0' || !inp || inp[0] == '\0')
	{
		return (-1);
	}
	file_d = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);

	if (file_d < 0)
	{
		return (-1);
	}
	while (inp[length])
	{
		length++;
	}
	w = write(file_d, inp, length);
	if (w < 0)
	{
		close(file_d);
		return (-1);
	}
	close(file_d);
	return (0);
}

/**
 * display_hist - display history of user input
 *
 * Return: 0 on success, -1 if fails
 */

int display_hist(void)
{
	FILE *file;
	char *filename = "my_simple_shell_history";
	char *line = NULL, *line_str;
	size_t length = 0;
	ssize_t read;
	int count = 0;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error opening file '%s'\n", filename);
		return (-1);
	}
	while ((read = getline(&line, &length, file)) != -1)
	{
		count++;
		line_str = my_itoa(count);
		if (line_str == NULL)
		{
			fclose(file);
			free(line);
			return (-1);
		}
		my_printf("%s %s", line_str, line);
		free(line_str);
	}
	if (line)
		free(line);
	fclose(file);
	return (0);
}
