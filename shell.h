#ifndef SHELL_H
#define SHELL_H

/* Include necesary header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

/* Read/Write Buffer */
#define BUFSIZE 1024 /* Buffer size for getline() */
#define DELIM " \t\n\r" /* Delimiters for strtok() */

/* Function Prototypes */
void sigint_handler(int signum);
char **split_line(char *line);
int execute(char **args, char **env);
int _strcmp(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getline(int fd);
int refill_buffer(int fd, char *buffer, int *size, int *index);

#endif /* SHELL_H */
