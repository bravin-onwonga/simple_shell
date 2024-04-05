#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	/**
	 * create a program that reads a prompt and then prints
	 * here is your prompt
	 * enter your prompt: inputs command
	 * your command is: inputted comand ;)
	 * enter your prompt
	 */

	char *input;
	size_t n = 0;

	while (1)
	{
		printf("$ enter your prompt: ");

		if (getline(&input, &n, stdin) == -1)
		{
			free(input);
			perror("Can't read");
			exit(EXIT_FAILURE);
		}

		if (strcmp(input, "EOF\n") == 0)
		{
			break;
		}

		fprintf(stdout, "Your command is: %s", input);
	}

	free(input);
	return (0);
}