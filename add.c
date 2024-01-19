#include "main.h"

/**
 * _add - This function adds the top two elements of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void _add(stack_t **top, uint line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
		add_error(line_number);

	tmp = (*top)->next;
	tmp->n += (*top)->n;
	pop_stack(top, line_number);
}
