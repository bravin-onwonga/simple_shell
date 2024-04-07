#include "main.h"

size_t _strlen(char *s);
int _strcmp(char *str1, char *str2);
int len_array(char **arr);

/**
 * main - Entry Point
 *
 * Return: 0 (success); otherwise -1
 */

int main(void)
{
	int status;
	char *stream = NULL, *path, **argv, *delim = "\n\t ";
	size_t len = 0;
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

		argv = split_string(stream, delim);

		if (argv && (argv[0] == NULL || argv[0][0] == '\0'))
		{
			free_array(argv);
			break;
		}

		path = find_path(argv[0], _strlen(argv[0]));

		if (path)
		{

			pid = fork();

			if (pid == -1)
			{
				free_array(argv);
				free(stream);
				perror("Fork Failed");
				exit(EXIT_FAILURE);
			}

			if (pid == 0)
			{
				if (_strcmp(stream, "env\n") == 0)
					print_env(environ);
				else
				{
					execute_function(path, argv);
				}
			}
			else
			{
				free_array(argv);
				free(stream);
				stream = NULL;
				len = 0;

				terminated_child = wait(&status);
				if (terminated_child == -1)
				{
					perror("Couldn't terminate:");
					exit(EXIT_FAILURE);
				}
			}
		}

		else
		{
			free_array(argv);
			free(stream);
			stream = NULL;
			len = 0;
			perror("Command not found");
			continue;
		}
	}
	free(stream);
	stream = NULL;
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
