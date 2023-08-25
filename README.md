# Readme file for monty

The pall() function prints all the elements in a stack.
Syntax: pall(stack_t **stack [, line_number]) [] indicates optional argument not used.

The push() function pushes an item into the stack.
Syntax: void push(stack_t **stack, unsigned int line_number);
It works by dynamically allocating memory for the item using malloc. 
On success, the item is inserted at the top of the stack.
If malloc fails, exit with error message and free stack.

The source code file - getfunc.c - contains the set of instructions to effectively select the appropraite function required to execute an opcode.
Syntax: void (*getfunc(char *opcode))(stack **stack, unsigned int line_number)
getfunc loops through a set of instructions, comparing opcode with the instructions.
on success, getfunc returns the opcode.
On failure, getfunc rturn NULL.

The free_stack() function frees the stack
Syntax: void free_stack(stack_t **stack).
free_stack free all the stack memory and set it to NULL

