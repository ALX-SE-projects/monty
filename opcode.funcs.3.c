#include "monty.h"

/**
 * __queue - __queue opcode
 * @LIFO: bool last-in-first-out
 */
void __queue(unsigned int *LIFO)
{
	*LIFO = 0;
}

/**
 * __pall - __pall opcode
 * @h: head of list
 */
void __pall(stack_t **h)
{
	print_dlistint(*h);
}
