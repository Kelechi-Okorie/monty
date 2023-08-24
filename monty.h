#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_var_s - global variable
 * @n: the integer to add to the stack
 * @top: top of the stack
 *
 * Description: global variable for the application
 */
typedef struct global_var_s
{
	char *argument;
	stack_t *top;
} global_var_t;

extern global_var_t global_var;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

void (*getfunc(char *opcode))(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */