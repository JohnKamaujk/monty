#include "monty.h"
/**
* switcher- handles the opcode
* @stack:  head linked list
* @line_counter: line_counter
* @file: poiner to monty file
* @content: line content
* 
*/
int switcher(char *content, stack_t **stack, unsigned int line_counter, FILE *file)
{
	instruction_t command_list[] = {
				{"push", push},
                {"pall", stack_printer},
                {"pint", pinter},
				{"pop", popper},
				{"swap", swapper},
				{"add", add_top_2},
				{"nop", nope},
				{"sub", subtract_top_2},
				{"div", divider},
				{"mul", multiplier},
				{"mod", modulator},
				{"pchar", print_char},
				{"pstr",print_str},
				{"rotl", rotater},
				{"rotr", s_rotator},
				{"queue", queues},
				{"stack", stack_printer},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *data;

	data = strtok(content, " \n\t");
	if (data && data[0] == '#')
		return (0);
	pusher.arg = strtok(NULL, " \n\t");
	while (command_list[i].opcode && data)
	{
		if (strcmp(data, command_list[i].opcode) == 0)
		{	command_list[i].f(stack, line_counter);
			return (0);
		}
		i++;
	}
	if (data && command_list[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, data);
		fclose(file);
		free(content);
		s_free(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}