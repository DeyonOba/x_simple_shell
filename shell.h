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

typedef struct error
{
	int error_num;
	char *(*func)(int num_shell_calls, char *failed_command);
} shell_error;

int _putchar(char c, int file_descriptor);
void _print(char *string, int file_descriptor);
void prompt(void);
char **WordParser(char *input, int *word_count, char *seperator);

char *(*get_error_message(int num))(int, char*);
char *command_error(int sh_call_num, char *command);
char *default_error(int sh_call_num, char *command);
char *file_error(int sh_call_num, char *command);


int digit_count(int number);
int _power(int digit_count);
int digit_to_char(int number);
char *number_to_string(int number);
int string_to_number(char *string);

char **get_paths_dir(char **env);
char *get_file_path(char *command, char **paths);

int exit_code(char **commands, int word_count);
void free_array(char **array);

#endif
