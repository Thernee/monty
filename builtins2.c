#include "monty.h"

/**
 * pint - prints integer at the top of stack
 * @stack: pointer to the stack
 * @line_number: line number of opcode
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	holder = *stack;
	if (holder == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		cleanupGlobals();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", holder->n);
}

/**
 * nop - This does nothing
 * @stack: pointer to stack
 * @line_number: line number of opcode
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;


	;
}
