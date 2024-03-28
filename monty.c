#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>

GLOBAL_VAR global_variable = {NULL, NULL, NULL, 0};

/**
 * main - entry point of the interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	char *input = NULL;
	size_t len = 0;
	int index = 0, indicatorFlag = 0, indicatorFlag2 = 0;
	ssize_t shows;
	stack_t *stack = NULL;

	if (argc != 2)
		display_usage_error();
	global_variable.fd = fopen(argv[1], "r");
	if (!global_variable.fd)
		display_open_error(argv[1]);
	shows = getline(&global_variable.buffer, &len, global_variable.fd);
	if (global_variable.buffer[0] == '#')
		shows = getline(&global_variable.buffer, &len, global_variable.fd);
	while (shows >= 0)
	{indicatorFlag = 0;
		indicatorFlag2 = 0;
		index++;
		input = strtok(global_variable.buffer, DELIM);
		global_variable.int_input = strtok(NULL, DELIM);
		if (input == NULL)
		{indicatorFlag2 = 1;
			bujo_nop(&stack, index); }
		if (indicatorFlag2 == 0)
		{
			if (input[0] == '#')
			{
				shows = getline(&global_variable.buffer,
						&len, global_variable.fd);
				indicatorFlag = 1; }}
		if (indicatorFlag == 0)
		{bujo_get_opcodes(input, &stack, index);
			shows = getline(&global_variable.buffer, &len,
					global_variable.fd); }}
			_freestack(stack);
			free(global_variable.buffer);
			global_variable.buffer = NULL;
			fclose(global_variable.fd);
			return (EXIT_SUCCESS);
}
