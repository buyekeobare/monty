#include "monty.h"

/**
 * bujo_pop_error - function that pops error message for empty stacks.
 * @line_number: instruction line number.
 * Return: EXIT_FAILURE.
 */
void bujo_pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	free_global_variables();
	exit(EXIT_FAILURE);
}

/**
 * bujo_pint_error - pfunction that pint error message for empty stacks.
 * @line_number: instruction line_number.
 * Return: EXIT_FAILURE
 */
void bujo_pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	free_global_variables();
	exit(EXIT_FAILURE);
}

/**
 * bujo_op_error - math function error messagess.
 * @line_number: instruction line_number.
 * @op_error: Operation where the error occurred.
 * Return: EXIT_FAILURE
 */
void bujo_op_error(unsigned int line_number, char *op_error)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op_error);
	free_global_variables();
	exit(EXIT_FAILURE);
}
/**
 * bujo_pchar_error - pchar error msg for 0 stack & and non-char val.
 * @line_number: instruction line_number
 * @error_msg: error message to print.
 * Return: EXIT_FAILURE.
 */
void bujo_pchar_error(unsigned int line_number, char *error_msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, error_msg);
	free_global_variables();
	exit(EXIT_FAILURE);
}

/**
* bujo_div_error - error for div by 0.
* @line_number: instruction line_number
* Return: EXIT_FAILURE
*/
void bujo_div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	free_global_variables();
	exit(EXIT_FAILURE);
}
