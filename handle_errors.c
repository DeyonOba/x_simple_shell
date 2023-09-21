#include "shell.h"

/**
 * get_error_message - Get function to handle error messages
 * @num: Error tag
 *
 * Return: Function pointer
 */
char *(*get_error_message(int num)) (char*, int, char*)
{
	size_t i, size;
	shell_error opps[] = {
		{0, default_error},
		{1, command_error},
		{2, file_error}
	};

	size = (sizeof(opps) / sizeof(shell_error));

	for (i = 0; i < size; i++)
	{
		if (opps[i].error_num == num)
		{
			return (opps[i].func);
		}
	}
	return (opps[0].func);

}

/**
 * command_error - Handles command error
 * @file_name: File name
 * @sh_call_num: Number of shell call (hsh)
 * @command: Command string
 *
 * Return: Error message
 */
char *command_error(char *file_name, int sh_call_num, char *command)
{
	char  *sep = ": ", *message = "not found";
	char *sh_call = number_to_string(sh_call_num);
	size_t string_len = 0;
	char *error_string;

	string_len += strlen(file_name) + strlen(sep) + strlen(sh_call);
	string_len += strlen(sep) +  strlen(command) + strlen(sep);
	string_len += strlen(message) + 2;

	error_string = malloc(string_len * sizeof(char));

	strcpy(error_string, file_name);
	strcat(error_string, sep);
	strcat(error_string, sh_call);
	strcat(error_string, sep);
	strcat(error_string, command);
	strcat(error_string, sep);
	strcat(error_string, message);
	strcat(error_string, "\n");

	return (error_string);
}

/**
 * default_error - Handles error
 * @file_name: File name
 * @sh_call_num: Number of shell call (hsh)
 * @command: Command string
 *
 * Return: Error message
 */
char *default_error(char *file_name, int sh_call_num, char *command)
{
	(void)file_name;
	(void)sh_call_num;
	(void)command;

	return ("");
}

/**
 * file_error - Handles file error
 * @file_name: File name
 * @sh_call_num: Number of shell call (hsh)
 * @command: Command string
 *
 * Return: Error message
 */
char *file_error(char *file_name, int sh_call_num, char *command)
{
	(void)file_name;
	(void)sh_call_num;
	(void)command;

	return ("");
}
