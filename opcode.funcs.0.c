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

void __swap(__attribute__((unused)) stack_t **h)
{
	/**/
}

void __add(__attribute__((unused)) stack_t **h)
{
	/**/
}



