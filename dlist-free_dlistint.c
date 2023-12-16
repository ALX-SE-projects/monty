#include "monty.h"
/**
 * free_dlistint - frees a stack_t list.
 * @head: head of list
 */
void free_dlistint(stack_t **head)
{
	stack_t *t;

	while ((t = *head) != NULL)
	{
		*head = (*head)->next;
		free(t);
	}
}
