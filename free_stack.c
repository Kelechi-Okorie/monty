#include "monty.h"

/**
 * free_stack - frees the stack
 * @stack: head of the stack
 *
 * Description: frees te stack
 * Return: always void
 */
void free_stack(stack_t **stack)
{
	stack_t *p, *temp;

	p = global_var.top;

	while (p)
	{
		temp = p->prev;
		free(p);
		p = temp;
	}

	*stack = NULL;
	global_var.top = NULL;
}
