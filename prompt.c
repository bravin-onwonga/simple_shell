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

	while (1)
	{
		len_prompt = _strlen(str);

		if (fwrite(str, 1, len_prompt, stdout) == -1)
		{
			perror("Write failed");
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
