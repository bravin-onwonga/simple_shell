#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == 0)
	{
		// Code executed by child process
		printf("Child Process\n");
		printf("%u I am child\n", child_pid);
	}
	else if (child_pid > 0)
	{
		// Code executed by parent process
		printf("Parent Process\n");
		printf("%u I am parent\n", child_pid);
	}
	else
	{
		// Error occurred during fork
		perror("fork");
		return 1;
	}

	return 0;
}
