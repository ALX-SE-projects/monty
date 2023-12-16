#include "monty.h"

extern unsigned int LIFO;
void __push(stack_t **h, int val)
{
	if (LIFO)
		add_dnodeint(h, val);
	else
		add_dnodeint_end(h, val);
}

void __pint(stack_t **h, char *strLineNumber)
{
	if (*h)
		printf("%d\n", (*h)->n);
	else
		exit_with_err(
			concat(3, "L", strLineNumber, ": can't pint, stack empty\n"), 1);
}

void __pop(stack_t **h, char *strLineNumber)
{
	stack_t *t;

	if (!h || !(*h))
		exit_with_err(
			concat(3, "L", strLineNumber, ": can't pop an empty stack\n"), 1);
	t = *h;
	*h = (*h)->next;
	free(t);
}

void __swap(stack_t **h, char *strLineNumber)
{
	int i = 0;
	stack_t *t = NULL;

	t = *h;
	while (t)
	{
		t = t->next;
		i++;
	}
	if (i < 2)
		exit_with_err(
			concat(3, "L", strLineNumber, ": can't swap, stack too short\n"),
				1);
	t = *h;
	*h = (*h)->next;
	t->next = (*h)->next;
	t->prev = *h;
	(*h)->next = t;
	(*h)->prev = NULL;
}

void __add(__attribute__((unused)) stack_t **h)
{
	/**/
}



