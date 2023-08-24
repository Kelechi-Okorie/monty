#include "monty.h"

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
	ssize_t line_len, nread;
	char *delims = " \n\t\r";
	int n;
	void (*f)(stack_t **stack, unsigned int line_number);
	unsigned int line_number;
	stack_t *head = NULL;

	line_len = nread = 0;
	lineptr = opcode = argument = NULL;
	n = 0;
	line_number = 0;

	if (argc != 2)
	{
		dprintf(2, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (!stream)
	{
		dprintf(2, "Error: can't open file %s\n", argv[1]);
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

		n = argument == NULL ? 0 : atoi(argument);
		global_var.argument = argument;

		f = getfunc(opcode);
		if (f)
		{
			f(&head, line_number);
		}
		else
		{
			dprintf(2, "Encounterd an error, opcode does not exits");
		}
	}

	return (0);
}
