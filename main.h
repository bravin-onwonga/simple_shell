#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

int _strlen(char *s);
void _strcpy(char *dest, char *src);
int get_spaces_count(char *str);
void execute_function(char *stream, size_t stream_len);
char **split_string(char *str);

#endif /* MAIN_H */
