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
	/* char *temp; */
	char *new_arr;
	unsigned int i = 0;

	/* fprintf(stdout, "Reallocating some memories\n"); */

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		new_arr = malloc(new_size);
		if (new_arr == NULL)
			return (NULL);
		return (new_arr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_arr = malloc(new_size);

	if (new_arr == NULL)
		return (NULL);

	for (i = 0; i < (old_size < new_size ? old_size : new_size); i++)
		new_arr[i] = ((char *)ptr)[i];

	free(ptr);
	return (new_arr);
}
