#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char **split_string(char *str);

int main()
{
	int i, j, status;
	size_t len_s, len;
	char stream[1024];
	char *str = "shell$ ";
	char **argv;
	pid_t pid, wait, terminated_child;

	while (1)
	{
		len_s = strlen(str);

		fwrite(str, 1, len_s, stdout);

		if (fgets(stream, sizeof(stream), stdin) == NULL)
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}

		len = strlen(stream);

		if (stream[0] == '.' && stream[1] == '/' || stream[0] == '/')
		{
			if (len > 0 && stream[len - 1] == '\n')
				stream[len - 1] = '\0';

			argv = split_string(stream);

			if (argv == NULL)
			{
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}

			pid = fork();

			if (pid == -1)
			{
				perror("Fork Failed");
				exit(EXIT_FAILURE);
			}

			else if (pid == 0)
			{

				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("execve");
				}

				free(argv);

				return (0);
			}

			else
			{
				terminated_child = waitpid(-1, &status, 0);
				if (terminated_child == -1)
				{
					perror("Couldn't exit");
					exit(EXIT_FAILURE);
				}
			}
		}

		else
		{
			if (strcmp(stream, "exit\n") == 0)
				break;

			if (fwrite(stream, 1, len, stdout) != len)
			{
				perror("Error writing to stdout");
				exit(EXIT_FAILURE);
			}
		}
	}

	exit(EXIT_SUCCESS);
}

char **split_string(char *str)
{
	int count = 0, j, i, len, k;
	char **arr;
	char *s, *token;
	const char *delim = " ";
	int *len_arr;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			count++;
	}
	count++;

	arr = malloc(sizeof(char *) * (count + 1));

	len_arr = malloc(sizeof(int) * count);

	if (arr == NULL || len_arr == NULL)
		return (NULL);

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
		arr[i] = malloc(sizeof(char) * (len + 1));
		if (arr[i] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		j++;
		i++;
	}

	j = 0;
	for (i = 0; i < count; i++)
	{
		k = 0;
		while (str[j] != ' ' && str[j] != '\0')
		{
			arr[i][k] = str[j];
			k++;
			j++;
		}
		arr[i][k] = '\0';
		j++;
	}

	arr[count] = NULL;

	return (arr);
}
