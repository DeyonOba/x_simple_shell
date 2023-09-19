#include "shell.h"


char *(*get_error_message(int num)) (int, char*)
{
	size_t i, size;
	shell_error opps[] = {
		{0, default_error},
		{1, command_error},
		{2, file_error}
	};

	size = (sizeof(opps) / sizeof (shell_error));

	for (i = 0; i < size; i++)
	{
		if (opps[i].error_num == num)
		{
			return (opps[i].func);
		}
	}
	return (opps[0].func);

}

char *command_error(int sh_call_num, char *command)
{
	/**
	 * Output should look something like this
	 * sh: 1: command_name: not found
	 */
	char *alert = "sh", *sep = ": ", *message = "not found";
	char *sh_call = number_to_string(sh_call_num);
	
	size_t string_len = strlen(alert) + strlen(sep) + strlen(sh_call) + strlen(sep) +  strlen(command) + strlen(sep) + strlen(message) + 2;

	char *error_string = malloc(string_len *sizeof(char));

	strcpy(error_string, alert);
	strcat(error_string, sep);
	strcat(error_string, sh_call);
	strcat(error_string, sep);
	strcat(error_string, command);
	strcat(error_string, sep);
	strcat(error_string, message);
	strcat(error_string, "\n");

	return (error_string);
}

char *default_error(int sh_call_num, char *command)
{
}

char *file_error(int sh_call_num, char *command)
{
}


