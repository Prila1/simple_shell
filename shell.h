#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

void sigint_handler(int signum);
char **split_line(char *line);
int execute(char **args, char **env);
int _strcmp(char *s1, char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
size_t _strlen(char *s);
char *_strdup(char *str);
char *build_path(char *dir, char *command);
char *find_path(char *command, char **env);
char *_strcat(char *dest, char *src);

#endif /* SHELL_H */
