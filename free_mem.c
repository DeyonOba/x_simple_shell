#include "shell.h"

/**
 * free_array - Free dynamically allocated memory
 *
 * @array: Array to be freed
 */
void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}
