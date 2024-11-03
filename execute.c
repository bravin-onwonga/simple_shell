#include "main.h"

/**
 * execute_function - executes a function using execve
 *
 * @str: string containing function and argumnent
 * @len: length of string
 */

void execute_function(char *str, char **argv)
{
	size_t len_str = _strlen(str);
	size_t len_arg = _strlen(argv[0]);

	argv[0] = _realloc(argv[0], len_arg, len_str);

	argv[0] = _strdup(str);

	if (execve(argv[0], argv, environ) == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}
