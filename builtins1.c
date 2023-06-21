#include "monty.h"

/**
 * push - Add node to the stack
 * @stack: Head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (!globalvar.token2 || !isdigit(globalvar.token2[0]))
	{
		free_dlistint(*stack);
		stderr_int(line_number);
	}

	n = atoi(globalvar.token2);
	create_node_stackend(stack, n);
}

/**
 * pall - Print the stack
 * @stack: Head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - Print the top element of the stack
 * @stack: Head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		pint_e(line_number);
		return;
	}

	printf("%d\n", (*stack)->n);
}

/**
 * swap - Swap the top two elements of the stack
 * @stack: Head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
		op_e(line_number, "swap");

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * nop - Does not do anything
 * @stack: Head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
