#include "main.h"

/**
 * _sub - This function prints the value at the top of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void _sub(stack_t **top, uint line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
		sub_error(line_number);

	tmp = (*top)->next;
	tmp->n -= (*top)->n;
	pop_stack(top, line_number);
}

/**
 * _div - This function divides the top two elements of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void _div(stack_t **top, uint line_number)
{
	stack_t *tmp = *top;

	if (tmp == NULL || tmp->next == NULL)
		div_error(line_number);

	if (tmp->n == 0)
		div_error2(line_number);

	tmp->next->n = tmp->next->n / tmp->n;
	*top = tmp->next;
	free(tmp);
}

/**
 * _mul - This function multiplies the top two elements of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void _mul(stack_t **top, uint line_number)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
		mul_error(line_number);

	tmp = (*top)->next;
	tmp->n *= (*top)->n;
	pop_stack(top, line_number);
}
