#include "monty.h"

/**
 * swap - swap the on the stack
 * @stack: the stack
 * @line_number: the line number
 *
 * Description: prints all elements on the stack
 * Return: always void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second, *temp;

	(void)stack;

	first = global_var.top;
	second = global_var.top->prev;
	temp = first;
	if (second == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		global_var.exit_status = 1;
		return;
	}

	temp->n = second->n;
	second->n = first->n;
	first->n = temp->n;
}
