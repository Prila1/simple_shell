#include "shell.h"

/**
 * build_path - Builds the full path of a command,
 * using a directory and a command
 * @dir: The directory to use
 * @command: The command to use
 *
 * Return: A pointer to the full path of the command, or NULL on failure
 */
char *build_path(char *dir, char *command)
{
	char *full_path = NULL;
	size_t len;

	if (dir == NULL || command == NULL)
		return (NULL);

	len = _strlen(dir) + _strlen(command) + 2;

	full_path = malloc(sizeof(char) * len);
	if (full_path == NULL)
		return (NULL);

	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, command);

	return (full_path);
}
