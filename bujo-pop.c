#include "monty.h"

/**
 * bujo_pop - removes the top element of the stack
 * @stack: head of linkedlist
 * @line_number: instruction line_number
 *
 * Return: void
 */
void bujo_pop(stack_t **stack, unsigned int line_number)
{

	stack_t *top = NULL;
	stack_t *top2 = NULL;
	int j = 0, k = 0, indicatorFlag = 0;

	if (stack == NULL)
	{
		_freestack(*stack);
		bujo_pop_error(line_number); }
	if (*stack == NULL)
	{
		_freestack(*stack);
		bujo_pop_error(line_number); }
	top = *stack;
	while (top->next != NULL)
	{
		top = top->next;
		j++;
		indicatorFlag = 1;
	}
	top2 = *stack;
	while (k < (j - 1))
	{
		top2 = top2->next;
		k++;
	}
	if (j == 0 && indicatorFlag == 0)
	{

		free(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		top2->next = NULL;
		free(top);
		top = NULL;
		return;
	}
}
