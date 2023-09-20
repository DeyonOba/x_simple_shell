#include "shell.h"

/**
 * _putchar - Outputs charactet to stdout
 * @c: Character
 * @file_descriptor: Std file descriptor
 *
 * Return: 0 (Success)
 */
int _putchar(char c, int file_descriptor)
{
		write(file_descriptor, &c, 1);

		return (0);
}

/**
 * _print - Print string to stdout
 * @string: String
 * @file_descriptor: Std file description
 */
void _print(char *string, int file_descriptor)
{
	int index = 0;

	while (string[index] != '\0')
	{
		_putchar(string[index], file_descriptor);
		index++;
	}
}

/**
 * prompt - Shell (hsh) prompt
 */
void prompt(void)
{
	char *alert = "($) ";

	_print(alert, 1);
}
