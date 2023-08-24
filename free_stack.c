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

	p = *stack;

	while (p)
	{
		temp = p->next;
		free(temp);
		p = temp;
	}

	*stack = NULL;
	global_var.top = NULL;
}
