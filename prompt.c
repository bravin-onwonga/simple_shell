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
	int len_prompt, status;
	char *str = "$ ", *stream = NULL;
	size_t len = 0, stream_len;
	pid_t pid, terminated_child;

	while (1)
	{
		len_prompt = _strlen(str);

		if (write(STDOUT_FILENO, str, len_prompt) == -1)
		{
			perror("Write failed");
			exit(EXIT_FAILURE);
		}

		if (getline(&stream, &len, stdin) == -1)
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}

		if (_strcmp(stream, "exit") == 0)
			break;

		stream_len = _strlen(stream);

		pid = fork();

		if (pid == -1)
		{
			perror("Fork Failed");
			exit(EXIT_FAILURE);
			break;
		}

		else if (pid == 0)
		{
			execute_function(stream, stream_len);
		}
		else
		{
			terminated_child = waitpid(-1, &status, 0);
			if (terminated_child == -1)
			{
				perror("Couldn't exit");
				exit(EXIT_FAILURE);
			}
		}
	}
	exit(EXIT_SUCCESS);
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
 */

int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str2[i] != '\n')
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		}
		i++;
	}

	return (0);
}
