#include "monty.h"

/**
 * getfunc - gets the appropriate function for the current instruction
 * @opcode: the opcode for the current instruction
 *
 * Description: gets the appropriate function for the current instruction
 * Return: a pointer to the function for current opcode
 */
void (*getfunc(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};

	i = 0;
	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i].f);

		i++;
	}

	return (NULL);
}
