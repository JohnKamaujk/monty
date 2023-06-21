#include "monty.h"

/**
 * free_stack - frees the stack
 * @head: stack Head
*/

void free_stack(stack_t *head)
{
	stack_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

