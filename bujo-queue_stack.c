#include "monty.h"

/**
 * create_stack_node - create a stack.
 * @stack: A pointer to top and bottom stack.
 * Return: EXIT SUCCESS
 */
int create_stack_node(stack_t **stack)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
		display_malloc_error();
	ptr->n = STACK;
	ptr->prev = NULL;
	ptr->next = NULL;

	*stack = ptr;

	return (EXIT_SUCCESS);
}
/**
 * freestack_node - Frees a stack_t stack.
 * @stack: A pointer to top and bottom stack.
 */
void freestack_node(stack_t **stack)
{
	stack_t *tmp_node = *stack;

	while (*stack)
	{
		tmp_node = (*stack)->next;
		free(*stack);
		*stack = tmp_node;
	}
}

/**
 * bujo_stack - a function that switches mode to stack
 * @stack: stack head
 * @line_number: instruction line_number
 * Return: void
 */
void bujo_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_variable.mode = 0;
}

/**
 * bujo_queue - a function that switches mode to stack
 * @stack: stack head
 * @line_number: instruction line_number
 * Return: void
 */

void bujo_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	global_variable.mode = 1;
}
