#include "monty.h"

/**
 * bujo_pall - prints the stack
 * @stack: head of linked list
 * @line_number: instruction line_number
 * Return: void
 */
void bujo_pall(stack_t **stack, unsigned int line_number)
{

	stack_t *aux = NULL;


	if (*stack == NULL)
	{
		return;
	}
	if (*stack == NULL && line_number != 1)
	{
		_freestack(*stack);
		free_global_variables();
		exit(EXIT_SUCCESS);
	}
	aux = *stack;
	while (aux->next != NULL)
		aux = aux->next;
	while (aux->prev != NULL)
	{
		printf("%d", aux->n);
		aux = aux->prev;
		printf("\n");
	}
	printf("%d\n", aux->n);
}

