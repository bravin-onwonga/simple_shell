#include "main.h"

int main(int ac __attribute__((unused)), char *argv[] __attribute__((unused)), char **env)
{
	printf("%p\n", env);
	printf("%p\n", environ);

	return (0);
}
