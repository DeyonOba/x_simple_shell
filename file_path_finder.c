#include "shell.h"

char **get_paths_dir(char **env)
{
        int i, var_count, path_count;
        char *result;
	size_t j;

        for (i = 0; env[i] != NULL; i++)
        {
                result = strstr(env[i], "PATH");

                if (result != NULL)
                {
                        char **varname_val = WordParser(env[i], &var_count, "=");
                        char **paths = WordParser(varname_val[1], &path_count, ":");
		       	size_t size = (sizeof(varname_val) / sizeof(varname_val[0]));

			for (j = 0; j < size; j++)
				free(varname_val[i]);
			free(varname_val);

			return (paths);
                }
        }
        return (NULL);
}

char *get_file_path(char *command, char **paths)
{

	int i;

	for (i = 0; paths[i] != NULL; i++)
	{
		struct stat fstatus;
		size_t len1, len2;
		
		len1 = strlen(paths[i]);
		len2 = strlen(command);
		
		char test_buffer[len1 + len2 + 2];

		strcpy(test_buffer, paths[i]);
		strcat(test_buffer, "/");
		strcat(test_buffer, command);


		if (stat(test_buffer, &fstatus) == 0)
		{
			char *buffer = malloc((strlen(test_buffer) + 1) * sizeof(char));

			if (buffer == NULL)
				return (NULL);

			strcpy(buffer, test_buffer);

			return (buffer);
		}
		else if (stat(command, &fstatus) == 0)
		{
			char *buffer = malloc( (len1 + 1) * sizeof(char));

			if (buffer == NULL)
				return (NULL);
			strcpy(buffer, command);

			return (buffer);
		}

	}
        return ("");
}
