#include "monty.h"

/**
 * is_valid_arg - checks if an argument is valid
 * @arg: the argument to check
 *
 * Description: checks if an argument is valid
 * Return: 1 for valid argument, 0 for invalid argument
 */
int is_valid_arg(char *arg)
{
	char *s;

	s = arg;
	if (*s == '-')
		s++;

	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);

		s++;
	}

	return (1);
}
