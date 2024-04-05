#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>

char *find_path(char *str, size_t len)
{
	int i = 0, k, j = 0;
	char *temp, **argv, *delim, *path;
	size_t len_path;
	struct stat st;

	temp = malloc(4);

	while (environ[i] != NULL)
	{
		k = 0;
		while (k < 4)
		{
			temp[k] = environ[i][k];
			k++;
		}
		if (strcmp(temp, "PATH") == 0)
		{
			delim = "=";
			argv = split_string(environ[i], delim);

			delim = ":";
			argv = split_string(argv[1], delim);
			break;
		}
		i++;
	}

	i = 0;

	while (argv[i] != NULL)
	{
		len_path = _strlen(argv[i]);

		path = malloc((len_path + len) + 2);

		if (path == NULL)
		{
			perror("Malloc failed find_path");
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

		if (stat(path, &st) == 0)
		{
			free(argv);
			printf("%s---\n", path);
			return (path);
		}
		else
		{
			j = 0;
			free(path);
		}
		i++;
	}

	free(argv);
	free(path);
	return (NULL);
}
