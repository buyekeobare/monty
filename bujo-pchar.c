i#include "monty.h"

/**
 * bujo_pchar - print the char value of the first element
 * @stack: head of linked list
 * @line_number: instruction line_number
 * Return: no return
 */
void bujo_pchar(stack_t **stack, unsigned int line_number)
{

	stack_t *tmp;

	if (*stack == NULL || stack == NULL)
	{
		bujo_pchar_error(line_number, "stack empty");
		return;
	}
	tmp = (*stack);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	if (tmp->n < 0 || tmp->n > 127)
	{
		bujo_pchar_error(line_number, "value out of range");
	}
	printf("%c\n", tmp->n);
}
