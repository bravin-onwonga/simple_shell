#include "main.h"

int getkeylen(char *s);

char *_getenv(char *var)
{
	char *value = NULL;
	char *hold = NULL;
	int i = 0, k = 0, n = 0, len_key, value_len;

	while (environ[i] != NULL)
	{
		len_key = getkeylen(environ[i]);
		printf("%d\n", len_key);

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
			printf("%d\n", value_len);
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

int main()
{
	const char *username = _getenv("SHELL"); // Get the value of the "USER" environment variable

	if (username != NULL)
	{
		printf("Hello, %s!\n", username);
	}
	else
	{
		printf("USER environment variable not found.\n");
	}

	return 0;
}

int getkeylen(char *s)
{
	int i = 0, len;

	while (s[i] != '=')
	{
		len++;
		i++;
	}
	len++;
	return (len);
}
