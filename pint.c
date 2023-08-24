#include "monty.h"

/**
 * pint - prints value at the top of the stack
 * @stack: the vm stack
 * @line_number: the current line number
 *
 * Description: prints value at the top of the stack
 * Return: always void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (global_var.top == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", global_var.top->n);
}
