# Readme file for monty

The pall() function prints all the elements in a stack.
syntax: pall(stack_t **stack [, line_number]) [] indicates optional argument not used.

The push() function pushes an item into the stack.
syntax:  push(stack_t **stack, unsigned int line_number);
It works by dynamically allocating memory for the item using malloc. 
On success, the item is inserted at the top of the stack.
If malloc fails, exit with error message and free stack.

