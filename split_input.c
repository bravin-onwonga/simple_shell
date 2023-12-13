#include "main.h"

void _strcpy(char *dest, char *src);
int get_spaces_count(char *str);

/**
 * split_string - splits a string into an array
 *
 * @str: string to split
 * Return: array of strings
 */

char **split_string(char *str)
{
	int i, count = 0, j = 0;
	char **arr;
	char *token;
	const char *delim = " ";

	count = get_spaces_count(str);

	arr = malloc(sizeof(char *) * (count + 1));

	if (arr == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);

	i = 0;
	while (token != NULL)
	{
		arr[i] = malloc(_strlen(token) + 1);
		if (arr[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(arr[j]);
			}
			free(arr);
			perror("Malloc fail");
			exit(EXIT_FAILURE);
		}
		_strcpy(arr[i], token);

		token = strtok(NULL, delim);
		i++;
	}

	arr[count] = NULL;

	i = 0;
	while (arr[i] != NULL)
	{
		printf("%s\n", arr[i]);
		i++;
	}

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
 * get_spaces_count - gets numberof spaces in a string
 *
 * @str: string
 * Return: number of spaces(success)
 */

int get_spaces_count(char *str)
{
	int i, count;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			count++;
	}
	count++;

	return (count);
}
