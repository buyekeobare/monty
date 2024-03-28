#include "monty.h"

/**
 * display_usage_error - prints an usage error message
 * Return: FAILURE
 */

void display_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * display_malloc_error - Prints malloc error messages.
 * Return: EXIT_FAILURE
 */

void display_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_global_variables();
	exit(EXIT_FAILURE);
}

/**
 *display_open_error - prints an open file error message
 *@file: type pointer of file
 * Return: FAILURE
 */

void display_open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * handle_push_error - handles a push error of int
 * @line_number: pointer of line_number
 * Return: EXIT_FAILURE
 */

void handle_push_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	free_global_variables();
	exit(EXIT_FAILURE);
}

/**
 * unknown_instruction_error - Error handler for unknown instructions
 * @line_number: instruction line_number
 * @input: type pointer char of the instruction.
 * Return: EXIT_FAILURE
 */

void unknown_instruction_error(char *input, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, input);
	free_global_variables();
	exit(EXIT_FAILURE);
}
