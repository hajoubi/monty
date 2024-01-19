#include "main.h"

/**
 * pint_stack - This function prints the value at the top of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void pint_stack(stack_t **top, uint line_number)
{
	stack_t *tmp = *top;

	if (tmp != NULL)
		printf("%d\n", tmp->n);
	else
		pint_error(line_number);
}

/**
 * pop_stack - This function removes the top element of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void pop_stack(stack_t **top, uint line_number)
{
	stack_t *tmp;

	tmp = *top;
	if (*top == NULL)
		pop_error(line_number);

	tmp = tmp->next;
	free(*top);
	*top = tmp;
}
