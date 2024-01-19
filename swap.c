#include "main.h"
/**
 * _swap - This function swaps the top two elements of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */


void _swap(stack_t **top, uint line_number)
{
	int num;

	if (*top == NULL || (*top)->next == NULL)
		swap_error(line_number);

	num = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = num;
}
