#include "main.h"

/**
  * free_array - handles freeing an array
  * @arr: array to free
 */

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
