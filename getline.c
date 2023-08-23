#include "shell.h"
/**
 * refill_buffer - Refills the buffer from a file descriptor
 * @fd: The file descriptor to read from
 * @buffer: The buffer to store characters
 * @size: The number of characters read from fd
 * @index: The current index in the buffer
 * Return: 0 on success, -1 on failure or end of file
 */
int refill_buffer(int fd, char *buffer, int *size, int *index)
{
	*size = read(fd, buffer, BUFSIZE); /* Read from fd */
	if (*size == -1 || *size == 0) /* If read fails or end of file */
		return (-1);

	*index = 0; /* Reset index */
	return (0);
}
/**
 * _getline - Reads a line from a file descriptor
 * @fd: The file descriptor to read from
 * Return: A pointer to the line, or NULL on failure or end of file
 */
char *_getline(int fd)
{
	static char buffer[BUFSIZE]; /* The buffer to store characters */
	static int index, size;
	char *line = NULL; /* The line to return */
	int len = 0; /* The length of the line */

	if (fd == -1) /* If invalid file descriptor, reset static variables */
	{
		index = 0;
		size = 0;
		return (NULL);
	}
	line = malloc(sizeof(char) * BUFSIZE); /* Allocate memory for line */
	if (line == NULL)
		return (NULL);
	while (1)
	{
		if (index == size) /* If buffer is empty, refill it */
		{
			if (refill_buffer(fd, buffer, &size, &index) == -1)
			{
				free(line);
				return (NULL);
			}
		}
		line[len] = buffer[index]; /* Copy char from buffer to line */
		len++;
		index++;
		if (len >= BUFSIZE) /* If line is full,reallocate more space */
		{
			line = _realloc(line, len, len + BUFSIZE);

			if (line == NULL)
				return (NULL);
		}
		if (line[len - 1] == '\n') /* If end of line, break the loop */
			break;
	}
	line[len] = '\0'; /* Add null terminator to line */
	return (line); /* Return the line */
}
