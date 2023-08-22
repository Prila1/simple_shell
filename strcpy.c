#include "shell.h"

/**
 * _strcpy - Copies a string to another buffer
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: A pointer to the destination buffer
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (ptr);
}
