#include "monty.h"

/**
 * __pchar - __pchar opcode
 * @h: head of list
 * @strLineNumber: (char *) lineNumber
 */
void __pchar(stack_t **h, char *strLineNumber)
{
	if (!h || !(*h))
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": can't pchar, stack empty\n"),
				1, h);
	if ((*h)->n < 0 || (*h)->n >= 128)
		exit_with_err(
			concat(h, 3, "L", strLineNumber,
				   ": can't pchar, value out of range\n"), 1, h);
	printf("%c\n", (*h)->n);
}

/**
 * __pstr - __pstr opcode
 * @h: head of list
 */
void __pstr(stack_t **h)
{
	stack_t *t;

	t = *h;
	while (t && t->n > 0 && t->n < 128)
	{
		printf("%c", t->n);
		t = t->next;
	}
	printf("\n");
}

/**
 * __rotl - __rotl opcode
 * @h: head of list
 */
void __rotl(stack_t **h)
{
	stack_t *t1 = NULL;
	stack_t *t2 = NULL;

	if (!(*h))
		return;
	if (!((*h)->next))
		return;
	t1 = (*h)->next;
	t2 = *h;
	while (t2->next)
		t2 = t2->next;
	t1->prev = NULL;
	t2->next = *h;
	(*h)->next = NULL;
	(*h)->prev = t2;
	*h = t1;
}

/**
 * __rotr - __rotr opcode
 * @h: head of list
 */
void __rotr(stack_t **h)
{
	stack_t *t = NULL;

	if (!(*h))
		return;
	if (!((*h)->next))
		return;
	t = *h;
	while (t->next)
		t = t->next;
	t->prev->next = NULL;
	t->next = *h;
	t->prev = NULL;
	(*h)->prev = t;
	*h = t;
}

/**
 * __stack - __stack opcode
 * @LIFO: bool last-in-first-out
 */
void __stack(unsigned int *LIFO)
{
	*LIFO = 1;
}
