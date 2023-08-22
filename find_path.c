#include "shell.h"

/**
 * find_path - Finds the path of a command using the PATH environment variable
 * @command: The command to find the path for
 * @env: The array of environment variables
 *
 * Return: A pointer to the path of the command, or NULL if not found
 */
char *find_path(char *command, char **env)
{
	char *path = NULL;
	char *path_copy = NULL;
	char *token = NULL;
	char *full_path = NULL;
	struct stat st;

	if (command == NULL || env == NULL)
		return (NULL);
	path = getenv("PATH"); /* Get the value of the PATH variable */
	if (path == NULL)
		return (NULL);

	path_copy = _strdup(path); /* Make a copy of the path */
	if (path_copy == NULL)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = build_path(token, command);
		if (full_path == NULL)
			return (NULL);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
