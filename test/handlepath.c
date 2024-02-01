#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;
int getkeylen(char *s);

char *_getenv(char *var)
{
	char *value = NULL;
	char *hold = NULL;
	int i = 0, k = 0, n = 0, len_key, value_len;

	while (environ[i] != NULL)
	{
		len_key = getkeylen(environ[i]);

		hold = malloc(len_key + 1);

		if (hold == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		while (environ[i][k] != '=' && environ[i][k] != '\0')
		{
			hold[k] = environ[i][k];
			k++;
		}
		k++;

		if (strcmp(hold, var) == 0)
		{
			value_len = (strlen(environ[i]) - len_key) + 1;

			value = malloc(value_len + 1);

			if (value == NULL)
			{
				perror("I just can't");
				free(hold);
				exit(EXIT_FAILURE);
			}

			while (environ[i][k] != '\0')
			{
				value[n] = environ[i][k];
				n++;
				k++;
			}
			break;
		}
		k = 0;
		hold = NULL;
		i++;
	}
	return (value);
}

int getkeylen(char *s)
{
	int i = 0, len = 0;

	while (s[i] != '=')
	{
		len++;
		i++;
	}
	len++;

	return (len);
}

int main()
{
	char *path_key = "PATH";
	const char *delim = ":";
	char *value, *token;

	value = _getenv(path_key);

	token = strtok(value, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}

	free(value);
	return (0);
}