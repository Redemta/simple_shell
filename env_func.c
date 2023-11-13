#include "shell.h"

/**
 * create_env_array - create array of environment variables
 * @env: array of environmental variable
 *
 * Return: void
 */

void create_env_array(char **env)
{
	unsigned int count = 0;

	while (environ[count] != NULL)
	{
		env[count] = my_strdup(environ[count]);
		count++;
	}
	env[count] = NULL;
}

/**
 * my_getenv_value - get the value of an environment variable by name
 * @name: Name of the environment variable to find.
 *
 * Return: Value of the environment variable (char *) or NULL if not found
 */

char *my_getenv_value(const char *name)
{
	size_t i = 0;
	const char *value, *result;

	if (name == NULL)
	{
		return (NULL);
	}
	while (environ[i] != NULL)
	{
		result = my_strchr(environ[i], '=');

		if (
			result != NULL
			&& result == environ[i]
			&& my_strncmp(environ[i], name,
			result - environ[i]) == 0
		   )
		{
			value = result + 1;
			return (my_strdup((char *)value));
		}
		i++;
	}
	return (NULL);
}
