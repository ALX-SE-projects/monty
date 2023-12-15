#include "monty.h"
/**
 * free_dlistint - frees a stack_t list.
 * @head: head of list
 */
void free_dlistint(stack_t *head)
{
	stack_t *next = NULL;

	if (!head)
		return;
	if (!(head->next))
	{
		free(head);
		return;
	}
	next = head->next;
	while (next)
	{
		free(next->prev);
		if (next->next)
			next = next->next;
		else
		{
			free(next);
			break;
		}
	}
}
