#include "main.h"

void free_array(char **arr)
{
	int i = 0;

	if (arr == NULL)
        return;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}
