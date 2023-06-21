#include "monty.h"
/**
* free_singly_linked_list - frees a doubly linked list
* @head: head of the stack
*/
void free_singly_linked_list(stack_t *head)
{
	stack_t *temp_head;

	temp_head = head;
	while (head)
	{
		temp_head = head->next;
		free(head);
		head = temp_head;
	}
}
