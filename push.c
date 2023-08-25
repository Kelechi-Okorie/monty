#include "monty.h"

/**
 * push - pushes an element on the stack
 * @stack: the stack
 * @line_number: the line number of the instruction
 *
 * Description: pushes an element on the stack
 * Return: always void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	int n;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fflush(stdout);
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		global_var.exit_status = 1;
		return;
	}

	if (global_var.argument == NULL || !is_valid_arg(global_var.argument))
	{
		fflush(stdout);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new);
	/*	free_stack(stack); */
		global_var.exit_status = 1;
		return;
	}

	n = atoi(global_var.argument);

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new;
		global_var.top = new;
		return;
	}

	global_var.top->next = new;
	new->prev = global_var.top;
	global_var.top = new;
}
