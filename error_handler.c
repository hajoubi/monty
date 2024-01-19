#include "main.h"


/**
 * open_error - Handles error when file cannot be opened.
 * @argv: Command-line arguments.
 */
void open_error(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}


/**
 * malloc_error - Handles error when a dynamic memory allocation fails.
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
#include "main.h"

/**
 * error_arguments - Handles error when required arguments are missing.
 */
void error_arguments(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}


/**
 * invalidInstruction_error - Handles error
 * when encountering an unknown instruction.
 * @invalidInstruction: The invalid instruction encountered.
 * @line: The line number where the error occurred.
 */
void invalidInstruction_error(char *invalidInstruction, uint line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, invalidInstruction);
	exit(EXIT_FAILURE);
}

/**
 * not_int_err - Handles error when "push"
 * instruction is not followed by an integer.
 * @line: The line number where the error occurred.
 */
void not_int_err(uint line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
