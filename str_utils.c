#include "shell.h"

int _putchar(char c, int std_file_num)
{
		write(1, &c, std_file_num);
}

void _print(char *string, int std_file_num)
{
	int index = 0;

	while(string[index] != '\0')
	{
		_putchar(string[index], std_file_num);
		index++;
	}
}

void prompt(void)
{
	char *alert = "($) ";
	_print(alert, 1);
}
