#include "shell.h"

char **WordParser(char *input, int *word_count, char *seperator)
{
        char **words = malloc(MAX_WORDS * sizeof(char *));

        if (words == NULL)
        {
                perror("Memory Allocation Failed");
                exit(-1);
        }
	
        char buffer[strlen(input) + 1];
        strcpy(buffer, input);

        char *token = strtok(buffer, seperator);
        int count = 0;

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
	*word_count = count;
	return (words);
}
