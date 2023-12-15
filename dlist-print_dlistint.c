#include "monty.h"
/**
 * print_dlistint - prints all the elements of a stack_t list.
 * @h: head of list
 * Return: the number of nodes
 */
size_t print_dlistint(stack_t *h)
{
	size_t len = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		len++;
	}
	return (len);
}
