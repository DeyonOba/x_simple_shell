#include "shell.h"

/**
 * get_path_dir - Get Path directories
 * @env: Environment variable
 *
 * Return: Array of pointer
 */
char **get_path_dir(char **env)
{
	int i, var_count, path_count;
	char *result;

	for (i = 0; env[i] != NULL; i++)
	{
		result = strstr(env[i], "PATH");

		if (result != NULL)
		{
			char **varname_val = arg_parser(env[i], &var_count, "=");
			char **paths = arg_parser(varname_val[1], &path_count, ":");

			free_array(varname_val);
			return (paths);
		}
	}
	return (NULL);
}

/**
 * get_file_path - Get path to executable file
 * @command: Command string
 * @env: Array of pointer to environment variables
 *
 * Return: Path
 */
char *get_file_path(char *command, char **env)
{
	char **paths = get_path_dir(env);
	int i;

	for (i = 0; paths[i] != NULL; i++)
	{
		struct stat fstatus;
		char test_buffer[1000], *path;

		strcpy(test_buffer, paths[i]);
		strcat(test_buffer, "/");
		strcat(test_buffer, command);

		if (stat(test_buffer, &fstatus) == 0)
		{
			path = strdup(test_buffer);
			return (path);
		}
		else if (stat(command, &fstatus) == 0)
		{
			path = strdup(command);
			return (path);
		}
	}
	return (NULL);
}
