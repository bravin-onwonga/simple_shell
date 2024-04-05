#include "main.h"

void free_array(char **arr, int len_arr)
{
	int j = 0;

	while (j < len_arr)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
	perror("Malloc fail");
}
