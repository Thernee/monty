#include "monty.h"

/**
 * stderr_usage - Prints usage error message.
 */
void stderr_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * stderr_malloc - Prints malloc error message.
 */
void stderr_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * stderr_fopen - Prints fopen error message.
 * @filename: The filename that failed to open.
 */
void stderr_fopen(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * stderr_int - Prints error message for invalid integer argument.
 * @line_number: The line number where the error occurred.
 */
void stderr_int(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * stderr_unknown - Prints error message for unknown instruction.
 * @token: The unknown instruction token.
 * @line_number: The line number where the error occurred.
 */
void stderr_unknown(char *token, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	free_globalvars();
	exit(EXIT_FAILURE);
}
