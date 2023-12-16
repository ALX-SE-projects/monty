#include "monty.h"

/**
 * __push - __push opcode
 * @h: head of list
 * @val: int value
 * @LIFO: bool last-in-first-out
 */
void __push(stack_t **h, int val, unsigned int *LIFO)
{
	if (*LIFO)
		add_dnodeint(h, val);
	else
		add_dnodeint_end(h, val);
}

/**
 * __pint - __pint opcode
 * @h: head of list
 * @strLineNumber: (char *) lineNumber
 */
void __pint(stack_t **h, char *strLineNumber)
{
	if (*h)
		printf("%d\n", (*h)->n);
	else
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": can't pint, stack empty\n"),
				1, h);
}

/**
 * __pop - __pop opcode
 * @h: head of list
 * @strLineNumber: (char *) lineNumber
 */
void __pop(stack_t **h, char *strLineNumber)
{
	stack_t *t;

	if (!h || !(*h))
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": can't pop an empty stack\n"),
				1, h);
	t = *h;
	*h = (*h)->next;
	free(t);
}

/**
 * __swap - __swap opcode
 * @h: head of list
 * @strLineNumber: (char *) lineNumber
 */
void __swap(stack_t **h, char *strLineNumber)
{
	stack_t *t;

	if (get_dlist_len(h) < 2)
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": can't swap, stack too short\n"),
				1, h);
	t = *h;
	*h = (*h)->next;
	t->next = (*h)->next;
	t->prev = *h;
	(*h)->next = t;
	(*h)->prev = NULL;
}

/**
 * __add - __add opcode
 * @h: head of list
 * @strLineNumber: (char *) lineNumber
 */
void __add(stack_t **h, char *strLineNumber)
{
	stack_t *t = NULL;

	if (get_dlist_len(h) < 2)
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": can't add, stack too short\n"),
				1, h);
	t = (*h)->next;
	t->n += (*h)->n;
	__pop(h, strLineNumber);
}
