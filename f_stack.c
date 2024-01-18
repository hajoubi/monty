#include "main.h"

/**
* free_stack - function that frees a doubly linked list
* @head: head pointer to the stack
*
* Return: nothing
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

