#include "monty.h"

#include <stdio.h>

void nothing(void);
global_var_t global_var;

/**
 * main - the main program entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Description: the main program entry point
 * Return: 0 on success, another number on failure
 */
int main(int argc, char **argv)
{
	FILE *stream;
	char *lineptr, *opcode, *argument;
	size_t line_len;
	ssize_t nread;
	char *delims = " \n\t\r";
	void (*f)(stack_t **stack, unsigned int line_number);
	unsigned int line_number;
	stack_t *head = NULL;

	line_len = nread = 0;
	lineptr = opcode = argument = NULL;
	line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (!stream)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&lineptr, &line_len, stream)) != -1)
	{
		line_number++;
		opcode = strtok(lineptr, delims);

		if (opcode == NULL)
			continue;

		if (strcmp(opcode, "pall") != -1)
			argument = strtok(NULL, delims);

		global_var.argument = argument;

		f = getfunc(opcode);
		if (f)
		{
			f(&head, line_number);
		}
		else
		{
			fflush(stdout);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free_stack(&head);
			exit(EXIT_FAILURE);
		}
	}

	return (0);
}
