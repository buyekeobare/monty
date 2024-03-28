#include "monty.h"

/**
 * bujo_swap - swaps the top two elements of the stack.
 * @stack: head of linkedlist
 * @line_number: instruction line_number
 *
 * Return: No return
 */
void bujo_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int j, k;

	if (*stack == NULL || stack == NULL)
		bujo_op_error(line_number, "swap");

	tmp = (*stack)->next;
	if ((*stack)->next == NULL)
		bujo_op_error(line_number, "swap");
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	j = tmp->n;
	k = tmp->prev->n;
	tmp->n = k;
	tmp->prev->n = j;
}
