#include "main.h"

int _strlen(char *s);

/**
 * main - Entry Point
 *
 * Return: 0 (success); otherwise -1
 */

int main(void)
{
	int len_prompt, status;
	char *str = "#cisfun$ ", *stream = NULL;
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

		stream_len = strlen(stream);

		if ((stream[0] == '.' && stream[1] == '/') || stream[0] == '/')
		{
			pid = fork();

			if (pid == -1)
			{
				perror("Fork Failed");
				exit(EXIT_FAILURE);
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
		else
		{
			if (strcmp(stream, "exit\n") == 0)
				break;

			if (fwrite(stream, 1, stream_len, stdout) != stream_len)
			{
				perror("Error writing to stdout");
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

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}
