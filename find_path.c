#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>

char *find_path(char *str, size_t len)
{
	int i = 0, k = 0, j = 0;
	char *temp, **argv = NULL, *delim, *path = NULL, **arr = NULL;
	size_t len_path;
	/* struct stat st; */

	fprintf(stdout, "I am in the path file\n");

	while (environ[i] != NULL)
	{
		temp = malloc(5);

		if (temp == NULL)
		{
			perror("Malloc failed for temp");
			return NULL;
		}

		k = 0;
		while (k < 4)
		{
			temp[k] = environ[i][k];
			k++;
		}

		temp[k] = '\0';

		if (strcmp(temp, "PATH") == 0)
		{
			delim = "=";
			arr = split_string(environ[i], delim);

			delim = ":";
			argv = split_string(arr[1], delim);
			free(temp);
			temp = NULL;
			break;
		}
		free(temp);
		temp = NULL;
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

		if (access(path, F_OK | X_OK) != -1)
		{
			free_array(argv);
			free_array(arr);
			return (path);
		}
		else
		{
			free(path);
			path = NULL;
		}
		j = 0;
		i++;
	}

	free_array(argv);
	free_array(arr);
	free(path);
	return (NULL);
}
