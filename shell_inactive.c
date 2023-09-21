#include "shell.h"

/**
 * non_interactive_mode - Shell in inactive mode
 * @file_name: executable file name
 * @env: Environment varibale
 *
 * Return: Integer
 */
int non_interactive_mode(char *file_name, char **env)
{
	int  num_hsh_calls = 0, exit_status = 0;

	exit_status = shell_cpu(file_name, env, &num_hsh_calls);
	return (exit_status);
}
