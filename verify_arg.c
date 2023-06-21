#include "monty.h"

/**
 * verify_arg - verifies if the arguments are correct.
 * @ac: Argument Number.
 * @av: Argument Vector.
 * @file: File
*/

void verify_arg(int ac, char *av[], FILE *file)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
}
