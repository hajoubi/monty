#include "main.h"

/**
 * push_stack - This function pushes an element to the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void push_stack(stack_t **top, uint line_number)
{
	stack_t	*NewNode, *last;

	(void)line_number;
	NewNode = malloc(sizeof(stack_t));

	if (NewNode == NULL)
		malloc_error();

	NewNode->n = number;
	NewNode->prev = NULL;
	NewNode->next = NULL;

	if (*top == NULL) /* Validate if empty list*/
	{
		*top = NewNode;
	}
	else if (data_structure_type == 1) /* If it's a queue */
	{
		last = *top;
		while (last->next != NULL) /* Go to the end */
			last = last->next;
		NewNode->prev = last;
		last->next = NewNode;
	}
	else /* if it's not empty list and it's a stack */
	{
		NewNode->next = *top;
		(*top)->prev = NewNode;
		*top = NewNode;
	}
}


/**
 * pall_stack - This function prints all the values on the stack.
 *
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */

void pall_stack(stack_t **top, uint line_number)
{
	stack_t *tmp = *top;

	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free_stack - This function frees the stack.
 *
 * @top: Pointer to the top of the stack.
 */

void free_stack(stack_t *top)
{
	stack_t *temp;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	free(top);
}

/**
 * _stack - Sets the format of the data to a stack (LIFO).
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void _stack(stack_t **top, uint line_number)
{
	(void) top;
	(void) line_number;
	data_structure_type = 0;
}

/**
 * _queue - Sets the format of the data to a queue (FIFO).
 * @top: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void _queue(stack_t **top, uint line_number)
{
	(void) top;
	(void) line_number;
	data_structure_type = 1;
}
