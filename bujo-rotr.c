#include "monty.h"

/**
 * bujo_rotr - rotate to left
 * @stack: head of linked list
 * @line_number: instruction line_number
 */
void bujo_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top2 = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;
	top2 = *stack;
	while (top2->next != NULL)
		top2 = top2->next;
	top2->next = *stack;
	(*stack)->prev = top2;
	top2 = (*stack)->next;
	(*stack)->next = NULL;
	*stack = top2;
	(*stack)->prev = NULL;
}
