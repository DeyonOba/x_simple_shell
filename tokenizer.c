#include "shell.h"

/**
 * arg_parser - Argument token
 * @input: stdin
 * @arg_count: argument count
 * @seperator: String seperator
 *
 * Return: Array of character pointers
 */
char **arg_parser(char *input, int *arg_count, char *seperator)
{
	char **words = malloc(MAX_WORDS * sizeof(char *));
	char buffer[1000];
	char *token;
	int count = 0;

	if (words == NULL)
	{
		perror("Memory Allocation Failed");
		exit(-1);
	}
	strcpy(buffer, input);
	token = strtok(buffer, seperator);

	while (token != NULL)
	{
		words[count] = malloc((strlen(token) + 1) * sizeof(char));

		if (words[count] == NULL)
		{
			perror("Memory Allocation Failed");
			exit(-1);
		}

		strcpy(words[count], token);
		token = strtok(NULL, seperator);
		count += 1;

		if (count > MAX_WORDS)
		{
			perror("Maximum words Exceeded");
			break;
		}
	}
	*arg_count = count;
	return (words);
}

/**
 * shell_read_line - Read line from stdin
 * @commands: String Arguments
 *
 * Return: Interger of strtok
 */
int shell_read_line(char **commands)
{
	size_t size = 0;
	int exit_code = getline(commands, &size, stdin);

	return (exit_code);
}
