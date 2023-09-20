#ifndef SHELL_H
#define SHELL_H
#define MAX_WORDS 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/**
 * struct error - Structure handles errors
 *
 * @error_num: The error number/ tag
 * @func: The function associated with the error
 */
typedef struct error
{
	int error_num;
	char *(*func)(char *file_name, int num_shell_calls, char *failed_command);
} shell_error;

int _putchar(char c, int file_descriptor);
void _print(char *string, int file_descriptor);
void prompt(void);
char **arg_parser(char *input, int *arg_count, char *seperator);
int shell_read_line(char **commands);
void exec_command(char *pathname, char **args, char **environ);

char *(*get_error_message(int num))(char *, int, char*);
char *command_error(char *file_name, int sh_call_num, char *command);
char *default_error(char *file_name, int sh_call_num, char *command);
char *file_error(char *file_name, int sh_call_num, char *command);


int digit_count(int number);
int _power(int digit_count);
int digit_to_char(int number);
char *number_to_string(int number);
int string_to_number(char *string);

char **get_path_dir(char **env);
char *get_file_path(char *command, char **env);

int exit_code(char **commands, int word_count);
void free_array(char **array);

int interactive_mode(char *filename, char **env);
int non_interactive(void);
int shell_cpu(char *file_name, char **env, int *num_hsh_calls);


#endif
