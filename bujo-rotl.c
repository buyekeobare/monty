#include "monty.h"

/**
 * bujo_rotl - rotates to the left
 * @stack: head of linked list
 * @line_number: instruction line_number
 */
void bujo_rotl(stack_t **stack, unsigned int line_number)
{

	stack_t *top2 = NULL;
	stack_t *top = NULL;
	(void)line_number;

	if (*stack == NULL || ((*stack)->next == NULL))
		return;
	top = *stack;
	while (top->next != NULL)
		top = top->next;
	top2 = top->prev;
	top2->next = NULL;
	top->prev = NULL;
	top->next = *stack;
	(*stack)->prev = top;
	*stack = top;
}
