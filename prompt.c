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
	int status, len_arr;
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
		len_arr = len_array(argv);

		if (argv && (argv[0] == NULL || argv[0][0] == '\0'))
		{
			free_array(argv, len_arr);
			break;
		}

		path = find_path(argv[0], _strlen(argv[0]));

		if (path)
		{

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
					execute_function(path, argv);
					free_array(argv, len_arr);
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
			}
		}

		else
			perror("Command not found");
	}
	free(stream);
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

int len_array(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		i++;

	return (i);
}
