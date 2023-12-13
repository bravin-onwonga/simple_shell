#include "main.h"

/**
 * print_env - prints the environment
 *
 * @environ: global variable environ
 */

void print_env(char **environ)
{
	int i = 0;
	ssize_t written_bytes;
	size_t len;

	if (environ == NULL)
	{
		perror("env");
		exit(EXIT_FAILURE);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		written_bytes = write(STDOUT_FILENO, environ[i], len);

		if (written_bytes == -1 || ((size_t)written_bytes != len))
		{
			perror("Write failed");
			exit(EXIT_FAILURE);
		}
		written_bytes = write(STDOUT_FILENO, "\n", 1);

		if (written_bytes == -1)
		{
			perror("Write failed");
			exit(EXIT_FAILURE);
		}
	}
}
