#include "main.h"

size_t _strlen(char *s);
int _strcmp(char *str1, char *str2);

/**
 * main - Entry Point
 *
 * Return: 0 (success); otherwise -1
 */

int main(void)
{
	int status, exit_status;
	char *stream = NULL;
	size_t len = 0, stream_len;
	pid_t pid, terminated_child;

	while (1)
	{
		if (getline(&stream, &len, stdin) == -1)
		{
			if (feof(stdin))
				continue;
			else
			{
				perror("Error reading input");
				exit(EXIT_FAILURE);
			}
		}

		if (_strcmp(stream, "exit\n") == 0)
		{
			free(stream);
			exit(EXIT_SUCCESS);
		}

		stream_len = _strlen(stream);

		pid = fork();

		if (pid == -1)
		{
			perror("Fork Failed");
			exit(EXIT_FAILURE);
		}

		else if (pid == 0)
		{
			if (_strcmp(stream, "env\n") == 0)
				print_env(environ);
			else
			{
				execute_function(stream, stream_len);
			}
		}
		else
		{
			terminated_child = waitpid(pid, &status, 0);
			if (terminated_child == -1)
			{
				perror("Couldn't exit");
				exit(EXIT_FAILURE);
			}

			if (WIFEXITED(status))
			{
				exit_status = WEXITSTATUS(status);
				if (exit_status != 0)
				{
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				fprintf(stderr, "Child process did not exit normally\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}

/**
 * _strlen - finds length of a string
 *
 * @s: pointer to the first character of string
 * @i - integer
 * Return: length of string
 */

size_t _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcmp - compares two strings
 *
 * @str1: first string
 * @str2: second string
 * Return: 0 (same); -1
 */

int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] != '\n' && str2[i] != '\n')
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
		i++;
	}

	if (str1[i] == '\n' && str2[i] == '\n')
	{
		return (0);
	}

	return (-1);
}
