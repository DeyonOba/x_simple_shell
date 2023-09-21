#include "shell.h"

/**
 * main - Execute Shell
 *
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment
 *
 * Return: Integer
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	if (isatty(0))
		return (interactive_mode(argv[0], env));

	return (non_interactive_mode(argv[0], env));
}
