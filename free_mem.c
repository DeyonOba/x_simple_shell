#include "shell.h"

void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}
