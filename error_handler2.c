#include "main.h"

/**
 * pint_error - This function prints the error message when pint fails.
 *
 * @line: Line number of the opcode.
 */

void pint_error(uint line)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);
	exit(EXIT_FAILURE);
}

/**
 * pop_error - This function prints the error message when pop fails.
 *
 * @line: Line number of the opcode.
 */

void pop_error(uint line)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}


/**
 * swap_error - This function prints the error message when swap fails.
 *
 * @line: Line number of the opcode.
 */

void swap_error(uint line)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}

void add_error(uint line)
{
	fprintf(stderr, "L%u: can't add, stack too short\n", line);
	exit(EXIT_FAILURE);
}


/**
 * sub_error - This function prints the error message when sub fails.
 *
 * @line: Line number of the opcode.
 */

void sub_error(uint line)
{
	fprintf(stderr, "L%u: can't sub, stack too short\n", line);
	exit(EXIT_FAILURE);
}
