#include "monty.h"

/**
 * bujo_push - Add node to the stack
 * @stack: head of linkedlist
 * @line_number: line number of the instruction
 * Return: void
 */
void bujo_push(stack_t **stack, unsigned int line_number)
{

	int n = 0;

	if (global_variable.int_input == NULL)
	{
		_freestack(*stack);
		handle_push_error(line_number);
	}
	if (!bujo_isdigit() || stack == NULL)
	{
		_freestack(*stack);
		handle_push_error(line_number);
	}
	n = atoi(global_variable.int_input);
	if (*stack  == NULL)
	{
		create_nodestack_front(stack, n);
	}
	else
	{
		create_nodestack_front(stack, n);
	}

	if (global_variable.mode == 1 && (*stack)->next != NULL)
		bujo_rotl(stack, line_number);
}
