#include "monty.h"

/**
 * bujo_pint - func that prints the value at the top of the stack
 * @stack: head of linked list
 * @line_number: instruction line_number
 *
 * Return: No return
 */
void bujo_pint(stack_t **stack, unsigned int line_number)
{

	stack_t *aux = NULL;

	if (stack == NULL || *stack == NULL)
	{
		bujo_pint_error(line_number);
		return;
	}
	aux = *stack;
	while (aux->next != NULL)
		aux = aux->next;

	printf("%d", aux->n);
	printf("\n");
}
