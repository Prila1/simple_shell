#include "shell.h"

/**
 * split_line - Splits a line into an array of words
 * @line: The line to split
 * Return: A pointer to the array of words, or NULL on failure
 */
char **split_line(char *line)
{
	char **args = NULL;
	char *token = NULL;
	size_t i = 0, size = 10;

	if (line == NULL)
		return (NULL);

	args = malloc(sizeof(char *) * size);
	if (args == NULL)
		return (NULL);

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		args[i] = token;
		i++;

		if (i == size)
		{
			size += 10;
			args = _realloc(args, sizeof(char *) * size,
					sizeof(char *) * (size + 10));
			if (args == NULL)
				return (NULL);
		}
		token = strtok(NULL, DELIM);
	}
	args[i] = NULL;

	return (args);
}
