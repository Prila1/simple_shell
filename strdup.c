#include "shell.h"

/**
 * _strdup - Duplicates a string using malloc
 * @str: The string to duplicate
 *
 * Return: A pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *dup = NULL;
	size_t len, i;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}
