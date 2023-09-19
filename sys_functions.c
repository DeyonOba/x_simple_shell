#include "shell.h"

int exit_code(char **commands, int word_count)
{

	if (word_count == 1)
		return (EXIT_SUCCESS);

	else if (word_count == 2)
	{
		int exit_code = string_to_number(commands[1]);

		if (exit_code >= 0)
			return(exit_code);
		else
			return(EXIT_FAILURE);
	}

	else
		return (EXIT_FAILURE);
}
