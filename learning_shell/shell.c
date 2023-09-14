#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#define MAX_WORDS 100

void prompt(void)
{
	printf("$ ");
}

char **WordParser(char *input, int *word_count)
{
	/** Allocates memory for the maximum number of words allowed*/
	char **words = malloc(MAX_WORDS * sizeof(char *));

	/** Checks for memory allocation faults*/
	if (words == NULL)
	{
		perror("Allocation Failed");
		exit(-1);
	}

	/** Since `strtok` replace the delimeter with a null byte terminator
	 * create a copy of the input data, for data integrity
	 */
	char buffer[strlen(input) + 1];
	strcpy(buffer, input);

	/* choose delimeters space, tab, new line, and return. Then create a token/ parse the
	 * data using the copied data `buffer`
	 */
	char *token = strtok(buffer, " \t\n\r");
	int count = 0;

	while (token != NULL)
	{
		words[count] = malloc((strlen(token) + 1) * sizeof(char));

		if (words[count] == NULL)
		{
			perror("Word allocation failed");
			exit(-1);
		}

		strcpy(words[count], token);

		token = strtok(NULL, " \t\n\r");
		count += 1;

		if (count > MAX_WORDS)
		{
			perror("Maximum words Exceeded");
			break;
		}
	}

	*word_count = count;
	return words;
}



int main(void)
{
	char *command = NULL;
	size_t size = 0;
	extern char** environ;

	while (1)
	{
		prompt();
		ssize_t read = getline(&command, &size, stdin);

		if (read == -1)
		{
			perror("EOF");
			break;
		}
		int word_counts = 0;
		char **words = WordParser(command, &word_counts);
		int i;
		
		if (word_counts > 0)
		{
			pid_t pid = fork();

			if (pid == 0)
			{
				if (execve(words[0], words, environ) == -1)
				{
					perror("Error command not found");
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











