#include "main.h"

/**
 * _realloc - function similar to realloc
 *
 * @ptr: old array
 * @old_size: size of old array
 * @new_size: size of new array
 * Return: reallocated array
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *temp;
	char *new_arr;
	unsigned int i, j;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
		{
			printf("Here1");
			return (NULL);
		}
		return (ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
	}
	temp = (char *)ptr;

	new_arr = malloc(new_size);

	if (new_arr == NULL)
	{
		printf("Here2");
		return (NULL);
	}

	i = 0;
	if (new_size < old_size)
	{
		while (i <= new_size)
		{
			new_arr[i] = temp[i];
			i++;
		}
	}
	j = 0;
	if (old_size < new_size)
	{
		while (j <= old_size)
		{
			new_arr[j] = temp[j];
			j++;
		}
	}
	ptr = (void *)new_arr;
	return (ptr);
}
