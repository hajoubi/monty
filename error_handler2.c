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

