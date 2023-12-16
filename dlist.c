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
	new = my_malloc(sizeof(stack_t), head);
	new->prev = NULL;
	new->next = *head;
	new->n = n;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}

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
	new = my_malloc(sizeof(stack_t), head);
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

/**
 * get_dlist_len - get length of the list
 * @h: head of list
 * Return: lenght of list
 */
size_t get_dlist_len(stack_t **h)
{
	size_t i = 0;
	stack_t *t;

	t = *h;
	while (t)
	{
		t = t->next;
		i++;
	}
	return (i);
}
