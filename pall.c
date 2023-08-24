#include "monty.h"

/**
 * pall - prints all elements on the stack
 * @stack: the stack
 * @line_number: the line number
 *
 * Description: prints all elements on the stack
 * Return: always void
 */
void pall(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *p;

	p = global_var.top;

	while (p)
	{
		printf("%d\n", p->n);
		p = p->prev;
	}
}
