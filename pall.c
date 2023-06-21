#include "monty.h"

/**
 * fpall - Prints all the values on the stack
 * @stack: Stack
 * @line_number: Line Number
*/

void fpall(stack_t **stack_head, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *temp;

	for (temp = *stack_head; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}