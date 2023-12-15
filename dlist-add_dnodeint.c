#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: head of list
 * @n: value of new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
		return (NULL);
	new = my_malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = *head;
	new->n = n;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}
