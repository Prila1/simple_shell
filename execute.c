#include "shell.h"

/**
 * execute - Executes a command using execve
 * @args: The array of arguments for the command
 * @env: The array of environment variables
 * Return: 0 on success, -1 on error or exit
 */
int execute(char **args, char **env)
{
	pid_t pid;
	int status;

	if (args == NULL || args[0] == NULL)
		return (0);

	/* if (_strcmp(args[0], "exit") == 0) */
		/* return (-1); */

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
			perror("./shell");
		exit(0);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
