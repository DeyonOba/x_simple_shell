#include "shell.h"

int _putchar(char c, int file_descriptor)
{
		write(file_descriptor, &c, 1);
}

void _print(char *string, int file_descriptor)
{
	int index = 0;

	while(string[index] != '\0')
	{
		_putchar(string[index], file_descriptor);
		index++;
	}
}

void prompt(void)
{
	char *alert = "($) ";
	_print(alert, 1);
}
