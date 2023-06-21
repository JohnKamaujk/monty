#include "monty.h"

/**
 * main -> Main function.
 * @ac: Argument Number.
 * @av: Argument Vector.
 * Return: depends on Condition.
 */
int main(int ac, char *av[])
{
	FILE *file = fopen(av[1], "r");
	int i;
	char *line = NULL;
	char *opcode = NULL;
	stack_t *stack = NULL;
	size_t line_length = 0;
	unsigned int line_number = 1;
	instruction_t command[] = {
		{"push", fpush}, {"pall", fpall}, {"pint", fpint}
	};
	verify_arg(ac, av, file);
	while (getline(&line, &line_length, file) != -1 && !feof(file))
	{
		opcode = strtok(line, " \n");
		if (opcode == NULL)
		{
			line_number++;
			continue;
		}
		for (i = 0; command[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, command[i].opcode) == 0)
			{
				command[i].f(&stack, line_number);
				break;
			}
		}
		if (command[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	free(line);
	free_stack(stack);
	fclose(file);
	return (0);
}
