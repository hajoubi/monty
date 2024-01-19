#include "main.h"
/**
 * div_error - This function prints the error message when div fails.
 *
 * @line: Line number of the opcode.
 */

void div_error(uint line)
{
	fprintf(stderr, "L%u: can't div, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * mul_error - This function prints the error message when mul fails.
 *
 * @line: Line number of the opcode.
 */

void mul_error(uint line)
{
	fprintf(stderr, "L%u: can't mul, stack too short\n", line);
	exit(EXIT_FAILURE);
}
