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
	char *command;

	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';

	argv = split_string(str);

	command = argv[0];

	if (argv[0] == NULL || argv[0][0] == '\0')
	{
		free(argv);
		return;
	}

	if (execve(command, argv, environ) == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}

	free(argv);
	exit(EXIT_SUCCESS);
}
