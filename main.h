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

size_t _strlen(char *s);
void _strcpy(char *dest, char *src);
char *_strdup(char *str, char *s);
int _strcmp(char *str1, char *str2);
void execute_function(char *str, char **argv);
char **split_string(char *str, char *delim);
void print_env(char **environ);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *find_path(char *str, size_t len);
void free_array(char **arr, int len_arr);
int len_array(char **arr);

#endif /* MAIN_H */
