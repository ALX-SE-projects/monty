#include "monty.h"

extern unsigned int LIFO;
void __push(stack_t **h, int val)
{
	if (LIFO)
		add_dnodeint(h, val);
	else
		add_dnodeint_end(h, val);
}

void __pint(__attribute__((unused)) stack_t **h)
{
	/**/
}

void __pop(__attribute__((unused)) stack_t **h)
{
	/**/
}

void __swap(__attribute__((unused)) stack_t **h)
{
	/**/
}

void __add(__attribute__((unused)) stack_t **h)
{
	/**/
}



