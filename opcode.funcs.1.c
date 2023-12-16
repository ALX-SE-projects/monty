#include "monty.h"

/**
 * __nop - __nop opcode
 */
void __nop(void)
{
}

/**
 * __sub - __sub opcode
 * @h: head of list
 * @strLineNumber: (char *) lineNumber
 */
void __sub(stack_t **h, char *strLineNumber)
{
	stack_t *t = NULL;

	if (get_dlist_len(h) < 2)
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": can't sub, stack too short\n"),
				1, h);
	t = (*h)->next;
	t->n -= (*h)->n;
	__pop(h, strLineNumber);
}

/**
 * __div - __div opcode
 * @h: head of list
 * @strLineNumber: (char *) lineNumber
 */
void __div(stack_t **h, char *strLineNumber)
{
	stack_t *t = NULL;

	if (get_dlist_len(h) < 2)
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": can't div, stack too short\n"),
				1, h);

	if ((*h)->n == 0)
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": division by zero\n"),
				1, h);
	t = (*h)->next;
	t->n /= (*h)->n;
	__pop(h, strLineNumber);
}

/**
 * __mul - __mul opcode
 * @h: head of list
 * @strLineNumber: (char *) lineNumber
 */
void __mul(stack_t **h, char *strLineNumber)
{
	stack_t *t = NULL;

	if (get_dlist_len(h) < 2)
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": can't mul, stack too short\n"),
				1, h);
	t = (*h)->next;
	t->n *= (*h)->n;
	__pop(h, strLineNumber);
}

/**
 * __mod - __mod opcode
 * @h: head of list
 * @strLineNumber: (char *) lineNumber
 */
void __mod(stack_t **h, char *strLineNumber)
{
	stack_t *t = NULL;

	if (get_dlist_len(h) < 2)
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": can't mod, stack too short\n"),
				1, h);
	if ((*h)->n == 0)
		exit_with_err(
			concat(h, 3, "L", strLineNumber, ": division by zero\n"),
				1, h);
	t = (*h)->next;
	t->n %= (*h)->n;
	__pop(h, strLineNumber);
}
