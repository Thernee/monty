#include "monty.h"

/**
 * pop_e - Prints error message for popping from an empty stack.
 * @line_number: The line number where the error occurred.
 *
 * Return: void
 */
void pop_e(unsigned int line_number)
{
	fprintf(stderr, "Error: Can't pop an empty stack - line %u\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * pint_e - Prints error message for printing from an empty stack.
 * @line_number: The line number where the error occurred.
 *
 * Return: void
 */
void pint_e(unsigned int line_number)
{
	fprintf(stderr, "Error: Can't pint, stack is empty - line %u\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * op_e - Prints error message for insufficient stack elements for an operation.
 * @line_number: The line number where the error occurred.
 * @op: The operation where the error occurred.
 *
 * Return: void
 */
void op_e(unsigned int line_number, char *op)
{
	fprintf(stderr, "Error: Insufficient stack elements for %s operation - line %u\n", op, line_number);
	exit(EXIT_FAILURE);
}

/**
 * pchar_e - Prints error message for invalid pchar operation.
 * @line_number: The line number where the error occurred.
 * @msg: The error message to print.
 *
 * Return: void
 */
void pchar_e(unsigned int line_number, char *msg)
{
	fprintf(stderr, "Error: Can't pchar, %s - line %u\n", msg, line_number);
	exit(EXIT_FAILURE);
}

/**
 * div_e - Prints error message for division by zero.
 * @line_number: The line number where the error occurred.
 *
 * Return: void
 */
void div_e(unsigned int line_number)
{
	fprintf(stderr, "Error: Division by zero - line %u\n", line_number);
	exit(EXIT_FAILURE);
}
