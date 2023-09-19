#include "shell.h"

int main(void)
{
	char *command = NULL;
	size_t size = 0;
	extern char** environ;
	int num_shell_calls = 0;

	while (1)
	{
		prompt();
		ssize_t read = getline(&command, &size, stdin);
		num_shell_calls++;

		if (read == -1)
		{
			perror("EOF");
			break;
		}
		int word_counts = 0;
		char **words = WordParser(command, &word_counts, " \n\t\r");
		int i;
		char **paths = get_paths_dir(environ);
		char *path = get_file_path(words[0], paths);

		if (word_counts == 0)
			continue;

		if (strcmp(words[0], "exit") == 0)
		{
			exit(exit_code(words, word_counts));
			break;
		}

		if (path == NULL || strcmp(path, "") == 0)
		{
			perror((get_error_message(1))(num_shell_calls, words[0]));
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

		for (i = 0; i < word_counts; i++)
		{
			free(words[i]);
		}

		free(words);
		continue;
	}
	return (0);
}
