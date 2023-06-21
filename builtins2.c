#include "monty.h"

/**
 * pop - Remove the top element of the stack
 * @stack: Pointer to the head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return value
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		pop_e(line_number);
		return;
	}

	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * add - Add the top two elements of the stack
 * @stack: Pointer to the head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return value
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		op_e(line_number, "add");
		return;
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - Subtract the top element of the stack from the second top element
 * @stack: Pointer to the head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return value
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		op_e(line_number, "sub");
		return;
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - Multiply the second element from the top of the stack by the top element
 * @stack: Pointer to the head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return value
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		op_e(line_number, "mul");
		return;
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - Print the character value of the top element of the stack
 * @stack: Pointer to the head of the linked list
 * @line_number: Line number of the instruction
 *
 * Return: No return value
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		pchar_e(line_number, "stack empty");
		return;
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		pchar_e(line_number, "value out of range");
		return;
	}

	printf("%c\n", (*stack)->n);
}
