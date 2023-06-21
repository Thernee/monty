#include "monty.h"
#include "main.h"

/**
 * div_m - Divides the second top node by the top element of the stack.
 * @stack: Head of the linked list
 * @line_number: Line number of the instruction
 */
void div_m(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_dlistint(*stack);
		op_e(line_number, "div");
	}

	stack_t *temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	if (temp->n == 0)
		div_e(line_number);

	temp->prev->n = temp->prev->n / temp->n;
	temp->prev->next = NULL;
	free(temp);
}

/**
 * mod_m - Computes the modulo of the second top node by the top element of the stack.
 * @stack: Head of the linked list
 * @line_number: Line number of the instruction
 */
void mod_m(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_dlistint(*stack);
		op_e(line_number, "mod");
	}

	stack_t *temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	if (temp->n == 0)
		div_e(line_number);

	temp->prev->n = temp->prev->n % temp->n;
	temp->prev->next = NULL;
	free(temp);
}

/**
 * pstr_t - Prints the string starting at the top of the stack.
 * @stack: Head of the linked list
 * @line_number: Line number of the instruction
 */
void pstr_t(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	while (temp != NULL && temp->n != 0 && (temp->n > 0 && temp->n < 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
	free_dlistint(*stack);
	free_globalvars();
	exit(EXIT_SUCCESS);
}
