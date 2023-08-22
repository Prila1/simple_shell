#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: The number of arguments passed to the program
 * @argv: The array of arguments passed to the program
 * @env: The array of environment variables
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args = NULL;
	int status;

	(void)argc;
	(void)argv;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		args = split_line(line);
		if (args == NULL)
			continue;
		status = execute(args, env);
		if (status == -1)
			break;
		free(line);
		free(args);
		line = NULL;
		args = NULL;
	}
	free(line);
	free(args);
	return (0);
}
