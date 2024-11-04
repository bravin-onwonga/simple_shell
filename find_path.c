#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>

char *get_full_path(char **argv, size_t len, char *str);

/**
  * find_path - finds the path to execute a command
  * @str: command
  * @len: length of command
  * Return: full executable path
  */

char *find_path(char *str, size_t len)
{
	int i = 0;
	char **argv = NULL, **arr = NULL;
	char *temp = NULL;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			temp = _strdup(environ[i]);

			if (temp == NULL)
			{
				perror("Malloc failed find path");
				return (NULL);
			}

			arr = split_string(temp, "=");

			free(temp);

			if (arr == NULL || arr[1] == NULL)
			{
				perror("Failed to parse PATH variable");
				free_array(arr);
				return (NULL);
			}

			argv = split_string(arr[1], ":");
			free_array(arr);
			break;
		}
		i++;
	}
	if (argv)
		return (get_full_path(argv, len, str));
	return (NULL);
}

/**
  * get_full_path - gets the full path
  * @argv: array of paths
  * @len: length of command
  * @str: command
  * Return: full path or NULL
  */

char *get_full_path(char **argv, size_t len, char *str)
{
	int i = 0, j = 0;
	size_t len_path = 0;
	char *path = NULL;

	while (argv[i] != NULL)
	{
		len_path = _strlen(argv[i]);

		path = malloc(len_path + len + 2);

		if (path == NULL)
		{
			perror("Malloc failed find path");
			free_array(argv);
			return (NULL);
		}

		_strcpy(path, argv[i]);
		path[len_path] = '/';
		len_path++;

		while (str[j] != '\0')
		{
			path[len_path] = str[j];
			j++;
			len_path++;
		}

		path[len_path] = '\0';

		if (access(path, F_OK | X_OK) != -1)
		{
			free_array(argv);
			return (path);
		}
		free(path);
		path = NULL;
		j = 0;
		i++;
	}

	free_array(argv);
	return (NULL);
}
