#include "monty.h"
/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list.
 * @head: head of list
 * @n: value of new item
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *current;

	if (!head)
		return (NULL);
	new = my_malloc(sizeof(stack_t));
	new->next = NULL;
	new->n = n;
	current = *head;
	while (current)
	{
		if (current->next)
			current = current->next;
		else
		{
			current->next = new;
			break;
		}
	}
	new->prev = current;
	if (!*head)
		*head = new;
	return (new);
}
