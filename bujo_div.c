#include "monty.h"

/**
 * bujo_div - divs element two by the top element.
 * @stack: head of linked list
 * @line_number: instruction line_number
 */
void bujo_div(stack_t **stack, unsigned int line_number)
{

	stack_t *top = NULL;
	stack_t *top2 = NULL;
	int j = 0, k = 0, indicatorFlag = 0;

	if (*stack == NULL || stack == NULL)
	{
		bujo_op_error(line_number, "div");
	}

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
		_freestack(*stack), bujo_op_error(line_number, "div");
	else
	{
		if (top->n == 0)
			bujo_div_error(line_number);
		top2->n = top2->n / top->n;
		top2->next = NULL;
		free(top);
		top = NULL;
		return;
	}
}
