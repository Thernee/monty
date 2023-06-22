#include "monty.h"

/**
 * pall - Prints values on the stack
 * @stack: pointer to head of stack
 * @line_numer: line number of opcode
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void)line_number;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_number:  line number of opcode
 * @n: variable
 * Return: address of new element
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *head = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->n = glob_vars.op_args;
	new->next = *stack;
	if (*stack)
		head->prev = new;
	*stack = new;
}

/**
 * pop - Removes the top element of the stack
 * @stack: pointer to head of stack
 * @line_number: line number
 * Return: nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}


	if (head)
	{
		*stack = head->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(head);
	}
}

/**
 * swap - Swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: file's line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head && head->next)
	{
		temp = head->next;
		if (temp->next)
			temp->next->prev = head;
		head->next = temp->next;
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		*stack = temp;
	}
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: pointer to head of stack
 * @line_number:  line number of opcode
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *holder;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		holder = head->next;
		holder->n += head->n;
		free(head);
		*stack = holder;
	}
}
