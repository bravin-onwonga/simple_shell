#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int count = 0, j, i, len, k;
	char str[] = "Hello World. Its a new day. I love coding.";
	char **arr;
	char *s, *token;
	const char *delim = " ";
	int *len_arr;

	for (i = 1; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			count++;
	}

	arr = malloc(sizeof(char *) * count);

	len_arr = malloc(sizeof(int) * count);

	if (arr == NULL || len_arr == NULL)
		return (-1);

	j = 0;
	i = 0;
	while (str[j] != '\0' && i < count)
	{
		len = 0;
		while (str[j] != ' ')
		{
			len++;
			j++;
		}
		len_arr[i] = len;
		j++;
		i++;
	}

	j = 0;
	for (i = 0; i < count; i++)
	{

		arr[i] = malloc(sizeof(char) * len_arr[i] + 1);
		token = malloc(sizeof(char) * len_arr[i] + 1);
		k = 0;
		while (k < len_arr[i])
		{
			token[k] = str[j];
			k++;
			j++;
		}
		j++;
		token[k] = '\0';
		strcpy(arr[i], token);
	}

	for (i = 0; i < count; i++)
	{
		printf("%s\n", arr[i]);
	}

	for (i = 0; i < count; i++)
	{
		free(arr[i]);
	}
	free(arr);

	return (0);
}
