#include "main.h"

/**
 * _pchar - This function prints the char at the top of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void _pchar(stack_t **top, uint line_number)
{
	int ascci_num;

	if (*top == NULL)
		pchar_error(line_number);

	ascci_num = (*top)->n;

	if (ascci_num < 0 || ascci_num > 127)
		pchar_error2(line_number);

	putchar(ascci_num);
	putchar('\n');
}


/**
 * _pstr - This function prints the string starting at the top of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void _pstr(stack_t **top, uint line_number)
{
	stack_t *tmp;
	int ascii_num;

	(void)line_number;
	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *top;
	while (tmp != NULL)
	{
		ascii_num = tmp->n;

		if (ascii_num <= 0 || ascii_num > 127)
			break;
		putchar(ascii_num);
		tmp = tmp->next;
	}
	putchar('\n');
}


/**
 * _rotl - This function rotates the stack to the top.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void _rotl(stack_t **top, uint line_number)
{
	stack_t *new_top, *tmp, *new_last;

	(void)line_number;

	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
		return;

	new_last = *top;
	tmp = *top;

	while (tmp->next)
		tmp = tmp->next;

	new_top = (*top)->next;
	new_last->next = NULL;
	new_last->prev = tmp;
	tmp->next = new_last;
	new_top->prev = NULL;
	*top = new_top;

}

/**
 * _rotr - This function rotates the stack to the bottom.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void _rotr(stack_t **top, uint line_number)
{
	stack_t *new_top, *tmp, *new_last;

	(void)line_number;

	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
		return;

	new_last = *top;
	tmp = *top;

	while (tmp->next)
		tmp = tmp->next;

	new_top = (*top)->next;
	new_last->next = NULL;
	new_last->prev = tmp;
	tmp->next = new_last;
	new_top->prev = NULL;
	*top = new_top;
}

/**
 * _mod - This function mods the top two elements of the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void _mod(stack_t **top, uint line_number)
{
	stack_t *tmp = *top;

	if (tmp == NULL || tmp->next == NULL)
		mod_error(line_number);

	if (tmp->n == 0)
		mod_error2(line_number);

	tmp->next->n = tmp->next->n % tmp->n;
	*top = tmp->next;
	free(tmp);
}
