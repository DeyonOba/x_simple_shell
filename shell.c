#include "shell.h"

int main(void)
{
	char *command = NULL, *path, **words, **paths;
	size_t size = 0, read;
	extern char** environ;
	int num_shell_calls = 0, word_counts = 0;

	while (1)
	{
		prompt();
		read = getline(&command, &size, stdin);
		num_shell_calls++;

		if (read == -1)
		{
			_putchar('\n', 1);
			break;
		}
		words = WordParser(command, &word_counts, " \n\t\r");
		if (word_counts == 0)
			continue;

		paths = get_paths_dir(environ);
		path = get_file_path(words[0], paths);

		if (strcmp(words[0], "exit") == 0)
		{
			exit(exit_code(words, word_counts));
			break;
		}

		if (path == NULL || strcmp(path, "") == 0)
		{
			_print((get_error_message(1))(num_shell_calls, words[0]), 2);
			continue;
		}

		if (word_counts > 0)
		{
			pid_t pid = fork();

			if (pid == 0)
			{
				if (execve(path, words, environ) == -1)
				{
					exit(EXIT_FAILURE);
				}
			}
			else if (pid > 0)
			{
				int status;

				waitpid(pid, &status, 0);
			}
			else
			{
				perror("Fork Error");
				exit(EXIT_FAILURE);
			}
		}

		free_array(words);

	}
	return (0);
}
