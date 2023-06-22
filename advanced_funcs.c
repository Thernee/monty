#include "monty.h"

/**
 * pstr - prints all the values of the stack as string
 *
 * @stack: The stack to be traversed
 * @line_number: The line number of opcode
 * Return: nothing
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;
	char str[1024] = {0};
	int i = 0, j;
	(void)line_number;

	holder = *stack;

	if (holder == NULL)
	{
		printf("\n");
		return;
	}

	while (holder != NULL && holder->n > 0 && holder->n < 128)
	{
		str[i] = (char)(holder->n);
		holder = holder->next;
		i++;
	}

	for (j = 0; j < i; j++)
	{
		printf("%c", str[j]);
	}

	printf("\n");
}

/**
 * pchar - converts the first element into char and prints
 *
 * @stack: pointer to the stack
 * @line_number: line number of opcode
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(glob_vars.buffer);
		fclose(glob_vars.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	holder = *stack;
	if (holder->n < 0 || holder->n >= 128)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(glob_vars.buffer);
		fclose(glob_vars.file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", holder->n);
}
