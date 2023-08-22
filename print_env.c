#include "shell.h"

/**
 * print_env - Prints the current environment
 * @env: The array of environment variables
 */
void print_env(char **env)
{
	int i;

	if (env == NULL)
		return;

	/* Loop through the array of environment variables */
	for (i = 0; env[i] != NULL; i++)
	{
		/* Write each variable to stdout */
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
