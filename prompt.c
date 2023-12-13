#include "main.h"

int _strlen(char *s);

/**
 * main - Entry Point
 *
 * Return: 0 (success); otherwise -1
 */

int main(void)
{
	int len_prompt;
	char *str = "$ ";
	char *stream = NULL;
	size_t len = 0;

	while (1)
	{
		len_prompt = _strlen(str);

		if (write(STDOUT_FILENO, str, len_prompt) == -1)
		{
			perror("Write failed");
			exit(EXIT_FAILURE);
		}

		if (getline(&stream, &len, stdin) == -1)
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}

/**
 * _strlen - finds length of a string
 *
 * @s: pointer to the first character of string
 * @i - integer
 * Return: length of string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}
