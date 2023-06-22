#include "monty.h"

#include "monty.h"
/**
 *rotr- rotates stack a stack from top to bottom
 *@stack: pointer to stack
 *@line_number: line number of opcode
 *Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *holder;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	holder = *stack;
	while (holder->next)
	{
		holder = holder->next;
	}
	holder->next = *stack;
	holder->prev->next = NULL;
	holder->prev = NULL;
	(*stack)->prev = holder;
	(*stack) = holder;
}

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

#include "monty.h"
/**
 * rotl- rotates 1st elem to bottom, second-last to top
 *@stack: pointer to stack
 *@line_number: opcode line number
 *Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *holder, *temp;
	(void)line_number;


	if (*stack == NULL || (*stack)->next == NULL)
		return;

	holder = *stack;
	temp = (*stack)->next;
	temp->prev = NULL;
	while (holder->next != NULL)
	{
		holder = holder->next;
	}
	holder->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = holder;
	(*stack) = temp;
}
