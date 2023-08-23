#include "shell.h"

/**
 * sigint_handler - Handles the SIGINT signal
 * @signum: The signal number
 */
void sigint_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "($) ", 4);
}
