#include "monty.h"

/**
 * bujo_pstr - prints the string starting at the top of the stack
 * @stack: head of linked list
 * @line_number: instruction line_number
 */
void bujo_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;

	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
		free_global_variables();
		exit(0);
	}
	tmp = *stack;
	if (tmp->next == NULL && line_number == 2 && (tmp->n < 0 || tmp->n >= 127))
	{
		printf("\n");
		_freestack(*stack);
		free_global_variables();
		exit(0);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->prev != NULL)
	{
		if (tmp->n > 0 && tmp->n < 127)
		{
			printf("%c", tmp->n);
			tmp = tmp->prev;
		}
		else
			tmp = tmp->prev;
		if (tmp->n <= 0 || tmp->n >= 127)
		{
			printf("\n");
			return;
		}
	}
	printf("%c\n", tmp->n);
}
