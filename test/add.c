#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a, b, res;

	if (argc != 3)
	{
		perror("Usage <function> int int");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	res = a + b;

	printf("%d\n", res);
}