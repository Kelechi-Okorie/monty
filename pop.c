#include "monty.h"

/**
 * pop - removes top of stack
 * @stack: the stack
 * @line_number: line number of the instruction
 *
 * Description: removes top of the stack
 * Return: always void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (global_var.top == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		global_var.exit_status = 1;
		return;
	}

	temp = global_var.top;
	global_var.top = global_var.top->prev;
	if (global_var.top)
		global_var.top->next = NULL;
	free(temp);

}
