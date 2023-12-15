#include "monty.h"

extern unsigned int LIFO;
void __push(stack_t **h, int val)
{
	if (LIFO)
		add_dnodeint(h, val);
	else
		add_dnodeint_end(h, val);
}

void __pint(stack_t **h)
{
	//
}

void __pop(stack_t **h)
{
	//
}

void __swap(stack_t **h)
{
	//
}

void __add(stack_t **h)
{
	//
}



