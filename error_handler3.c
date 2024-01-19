#include "main.h"

/**
 * mod_error - This function prints the error message when mod fails.
 *
 * @line: Line number of the opcode.
 */

void mod_error(uint line)
{
	fprintf(stderr, "L%u: can't mod, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * div_error2 - This function prints the error message when div fails.
 *
 * @line: Line number of the opcode.
 */

void div_error2(uint line)
{
	fprintf(stderr, "L%u: division by zero\n", line);
	exit(EXIT_FAILURE);
}

/**
 * mod_error2 - This function prints the error message when mod fails.
 *
 * @line: Line number of the opcode.
 */

void mod_error2(uint line)
{
	fprintf(stderr, "L%u: division by zero\n", line);
	exit(EXIT_FAILURE);
}

/**
 * pchar_error - This function prints the error message when pchar fails.
 *
 * @line: Line number of the opcode.
 */

void pchar_error(uint line)
{
	fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
	exit(EXIT_FAILURE);
}

/**
 * pchar_error2 - This function prints the error message when pchar fails.
 *
 * @line: Line number of the opcode.
 */

void pchar_error2(uint line)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
	exit(EXIT_FAILURE);
}
