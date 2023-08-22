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
	char *path = NULL;

	if (args == NULL || args[0] == NULL)
		return (0);
	if (_strcmp(args[0], "exit") == 0) /* Check if user types exit */
	{
		exit(0); /* Exit the shell */
	}
	if (_strcmp(args[0], "env") == 0) /* Check if user types env */
	{
		print_env(env); /* Print the current environment */
		return (0); /* Return success */
	}
	path = find_path(args[0], env); /* find the path of the command */
	if (path == NULL) /* if no path found, print error and return */
	{
		perror("./shell");
		return (0);
	}
	pid = fork(); /* Create a child process */
	if (pid == -1) /* if fork fails, print error and return */
	{
		perror("Error");
		return (-1);
	}
	else if (pid == 0) /* If child process */
	{
		/*Execute command with arguments and path */
		if (execve(path, args, env) == -1)
		{
			perror("./shell");
			exit(0);
		}
	}
	else /* if parent process */
	{
		wait(&status); /* wait for child process to finish */
	}
	free(path); /* Free the path */
	return (0); /* Return success */
}
