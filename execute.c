#include "main.h"

/**
 * execute_function - executes a function using execve
 *
 * @str: string containing function and argumnent
 * @len: length of string
 */

void execute_function(char *str, size_t len)
{
	char **argv;
	char *s;

	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';

	argv = split_string(str);

	if (execve(argv[0], argv, environ) == -1)
	{
		s = "./shell";
		perror(s);
		exit(EXIT_FAILURE);
	}

	free(argv);
}
