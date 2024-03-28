#include "monty.h"

/**
 * _freestack - free a linked list stack.
 * @stack: pointer to the first element of the list
 * Return: no return
 */
void _freestack(stack_t *stack)
{
	stack_t *helper = NULL;
	stack_t *aux = NULL;

	aux = stack;
	while (aux != NULL)
	{
		helper = aux->next;
		free(aux);
		aux = helper;
	}
	stack = NULL;
}

/**
 * free_global_variables - free a global buffer.
 *
 * Return: no return
 */
void free_global_variables(void)
{
	fclose(global_variable.fd);
	free(global_variable.buffer);
}

