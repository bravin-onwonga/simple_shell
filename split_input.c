#include "main.h"

void _strcpy(char *dest, char *src);
char *_strdup(char *str);

/**
 * split_string - splits a string into an array
 *
 * @str: string to split
 * Return: array of strings
 */

char **split_string(char *str, char *delim)
{
	int count = 0;
	char **arr = NULL, **temp;
	char *token;

	token = strtok(str, delim);

	while (token != NULL)
	{
		temp = _realloc(arr, count * sizeof(char *), (count + 1) * sizeof(char *));

		if (temp == NULL)
		{
			free_array(arr);
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		arr = temp;

		arr[count] = _strdup(token);

		if (!arr[count])
		{
			free_array(arr);
			printf("arr[count]");
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, delim);
		count++;
	}

	temp = _realloc(arr, count * sizeof(char *), (count + 1) * sizeof(char *));

	if (temp == NULL)
	{
		free_array(arr);
		perror("Memory allocation failed1");
		exit(EXIT_FAILURE);
	}

	arr = temp;
	arr[count] = NULL;

	return (arr);
}

/**
 * _strcpy - function similar to strcpy of standard library
 *
 * @dest: where to copy
 * @src: string to copy
 */

void _strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 * _strdup - duplicates a string
 *
 * @str: string to duplicate
 * Return: pointer to duplicated string
 */

char *_strdup(char *str)
{
	unsigned int len, i;
	char *cpy;

	i = 0;
	len = _strlen(str);

	cpy = malloc(sizeof(char) * len + 1);

	if (cpy == NULL)
		return (NULL);

	while (i < len)
	{
		cpy[i] = str[i];
		i++;
	}

	return (cpy);
}
