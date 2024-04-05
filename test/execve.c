
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int num_childern = 5, i;
	pid_t pid, terminated_child;
	int status;

	for (i = 0; i < num_childern; i++)
	{
		pid = fork();

		if (pid == 0)
		{

			if (execve(argv[0], argv, ) == -1)
			{
				perror("Execve");
				exit(EXIT_FAILURE);
			}
		}

		else if (pid == -1)
		{
			perror("Fork\n");
			exit(EXIT_FAILURE);
		}
	}

	for (i = 0; i < num_childern; i++)
	{
		terminated_child = waitpid(-1, &status, 0);
		if (terminated_child == -1)
		{
			perror("Couldn't exit");
			exit(EXIT_FAILURE);
		}
	}

	return (0);
}