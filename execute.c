#include "main.h"

/**
 * execute_function - executes a function using execve
 *
 * @str: string containing function and argumnent
 * @len: length of string
 */

void execute_function(char *str, char **argv)
{
	size_t len = _strlen(str);
	size_t len_arg = _strlen(argv[0]);

	argv[0] = _realloc(argv[0], len_arg, len);

	if (execve(str, argv, environ) == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}

	free(argv);
	exit(EXIT_SUCCESS);
}
