#include "monty.h"

/**
 * fpint - Prints the value at the top of the stack
 * @stack_head: Stack head
 * @line_number: Line Number
*/

void fpint(stack_t **stack_head, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack_head;
	if (temp == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
    printf("%d\n", temp->n);
}
