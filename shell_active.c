#include "shell.h"

int interactive_mode(void)
{
	while (1)
        {
                char *command = NULL, *path, **words, **paths;
                extern char **environ;
                int read, num_shell_calls = 0, word_counts = 0;

                prompt();
                read = shell_read_line(&command);
                num_shell_calls++;

                if (read == -1)
                {
                        _putchar('\n', 1);
                        break;
                }
                words = arg_parser(command, &word_counts, " \n\t\r");
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
			exec_command(path, words, environ);
                }

                free_array(words);

        }
        return (EXIT_SUCCESS);
}

void exec_command(char *pathname, char **args, char **environ)
{
	pid_t pid = fork();
	
	if (pid == 0)
	{
		if (execve(pathname, args, environ) == -1)
			perror("Execution failed");
	}

	else if (pid > 0)
	{
		int status;
		
		waitpid(pid, &status, 0);
	}

	else
		perror("Error");
}
