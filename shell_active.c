#include "shell.h"

/**
 * interactive_mode - Handle shell in interactive mode
 * @file_name: Name of excutable file
 * @env: Environment variable
 *
 * Return: sum of numbers
 */
int interactive_mode(char *file_name, char **env)
{
	int  num_hsh_calls = 0, exit_status = 0;

	while (1)
	{
		prompt();

		exit_status = shell_cpu(file_name, env, &num_hsh_calls);
		if (num_hsh_calls == -1)
			break;
	}
	return (exit_status);
}

/**
 * exec_command - Create processes and execute commands
 *
 * @pathname: String containg path directory
 * @args: Shell arguments
 * @environ: Environment variable
 */
void exec_command(char *pathname, char **args, char **environ)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(pathname, args, environ) == -1)
			perror(pathname);
	}

	else if (pid > 0)
	{
		int status;

		waitpid(pid, &status, 0);
	}

	else
		perror("Error");
}

/**
 * shell_cpu - Brain behind shell execution
 * @file_name: Executable file name
 * @env: Environment variable
 * @num_hsh_calls: Number of shell calls
 *
 * Return: Interger
 */
int shell_cpu(char *file_name, char **env, int *num_hsh_calls)
{
	char *command = NULL, *path, **words = NULL;
	int read, word_counts = 0;

	read = shell_read_line(&command);
	*num_hsh_calls += 1;

	if (read == -1)
	{
		_putchar('\n', 1);
		return (EXIT_FAILURE);
	}

	words = arg_parser(command, &word_counts, " \n\t\r");
	if (word_counts == 0)
		return (EXIT_SUCCESS);
	path = get_file_path(words[0], env);
	if (strcmp(words[0], "exit") == 0)
	{
		*num_hsh_calls = -1;
		return (exit_code(words, word_counts));
	}
	if (path == NULL)
	{
		_print((get_error_message(1))(file_name, *num_hsh_calls, words[0]), 2);
		return (EXIT_FAILURE);
	}

	if (word_counts > 0)
	{
		exec_command(path, words, env);

	}

	free_array(words);
	return (EXIT_SUCCESS);
}
