#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
size_t _strlen(char *s)
{
	size_t len = 0;

	while (*s++)
		len++;
	return (len);
}
