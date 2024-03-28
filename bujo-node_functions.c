#include "monty.h"

/**
 * create_nodestack_front - func that creates a node stack
 * @head: A pointer to top and bottom stack.
 * @n: value
 * Return: node
 */
stack_t *create_nodestack_front(stack_t **head, int n)
{
	stack_t *new_nodestack;

	if (head == NULL)
		return (NULL);
	new_nodestack = malloc(sizeof(stack_t));
	if (new_nodestack == NULL)
		display_malloc_error();
	new_nodestack->n = n;
	new_nodestack->next = *head;
	new_nodestack->prev = NULL;
	*head = new_nodestack;
	return (new_nodestack);
}

/**
 * create_nodestack_end - create a node stack at end.
 * @head: A pointer to top and bottom stack.
 * @n: the value
 * Return: the node
 */
stack_t *create_nodestack_end(stack_t **head, int n)
{
	stack_t *new_nodestack;
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	new_nodestack = malloc(sizeof(stack_t));
	if (new_nodestack == NULL)
		display_malloc_error();
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_nodestack;
	new_nodestack->n = n;
	new_nodestack->prev = tmp;
	new_nodestack->next = NULL;
	return (new_nodestack);
}
/**
 * add_newNode - adds new node at the beginning of dlistint_t list
 * @head: ptr to the first element of the list.
 * @n: integer
 * Return: the ptr to new node at the beginning of dlistint_t list.
 */
stack_t *add_newNode(stack_t **head, int n)
{
	stack_t *newNode = NULL;

	if (head == NULL)
		return (NULL);
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = n;
	if (*head == NULL)
	{
		newNode->next = *head;
		newNode->prev = NULL;
		*head = newNode;
		return (newNode);
	}
	newNode->n = n;
	(*head)->prev = newNode;
	newNode->next = *head;
	*head = newNode;
	return (newNode);
}
