#include "shell.h"

/**
 * execute_echo - Execute normal echo
 * @input: parsed command
 *
 * Return: 0 if success, -1 on failure
 */

int execute_echo(char *input[])
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (execvp(input[0], input) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (-1);
		}
		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "command execution failed\n");
			return (-1);
		}
	}
	return (0);
}
