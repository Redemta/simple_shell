#include "shell.h"

/**
 * my_realloc - reallocate memory block using malloc and free.
 * @ptr: pointer to memory block to reallocate.
 * @size_old: old size of memory block
 * @size_new: new size to reallocate memory block to
 * Return: pointer to newly allocated memory block.
 */

void *my_realloc(void *ptr, unsigned int size_old, unsigned int size_new)
{
	unsigned int copy_size;
	void *new_ptr;

	if (ptr == NULL)
	{
		return (malloc(size_new));
	}
	if (size_new == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size_new);

	if (new_ptr == NULL)
	{
		return (NULL);
	}
	copy_size = (size_old < size_new) ? size_old : size_new;
	my_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

/**
 * my_memcpy - copy bytes from source to destination
 * @dest: pointer to destination memory block
 * @src: pointer to source memory block
 * @num: no of bytes to copy
 *
 * Return: pointer to destination memory block
 */

void *my_memcpy(void *dest, const void *src, unsigned int num)
{
	unsigned int i;
	char *dest_char = (char *)dest;
	const char *src_char = (const char *)src;

	for (i = 0; i < num; i++)
	{
		dest_char[i] = src_char[i];
	}
	return (dest);
}

/**
 * my_free_array - free array of char pointers and single char pointer.
 * @cmd: array of char pointers to free
 * @line: single char pointer to free.
 */

void my_free_array(char **cmd, char *line)
{
	unsigned int i;

	if (cmd != NULL)
	{
		for (i = 0; cmd[i] != NULL; i++)
		{
			free(cmd[i]);
		}
		free(cmd);
	}
	if (line != NULL)
	{
		free(line);
	}
}

/**
 * my_memset - fill an array by a constant byte
 * @ptr: memory block to be filled
 * @val: constant byte value to fill
 * @num: no of bytes to fill
 *
 * Return: pointer to modified memory block
 */

void *my_memset(void *ptr, int val, unsigned int num)
{
	unsigned int i;
	char *char_ptr = (char *)ptr;

	for (i = 0; i < num; i++)
	{
		char_ptr[i] = (char)val;
	}
	return (ptr);
}

/**
 * my_malloc - aloocate memory for an array using malloc
 * @size: size of memory block to allocate
 *
 * Return: pointer to newly allocated memory block
 */

void *my_malloc(unsigned int size)
{
	void *ptr;

	ptr = malloc(size);

	return (ptr);
}
