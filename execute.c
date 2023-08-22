#include "shell.h"

/**
 * execute - Executes a command using execve
 * @args: The array of arguments for the command
 * @env: The array of environment variables
 *
 * Return: 0 on success, -1 on error or exit
 */
int execute(char **args, char **env)
{
	pid_t pid;
	int status;
	char *path = NULL;

	if (args == NULL || args[0] == NULL)
		return (0);
	  /* if (_strcmp(args[0], "exit") == 0) */
	  /* return (-1); */
	/* Find the path of the command */
	path = find_path(args[0], env);
	if (path == NULL)
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
		wait(&status);
	}
	free(path);
	return (0);
}
