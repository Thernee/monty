#include "monty.h"


/**
 * mul - multiplies top  elem with second top elem
 * @stack: pointer to lists for monty stac
 * @line_number: number of line opcode occurs on
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int holder;
	stack_t *temp;

	temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(glob_vars->buffer);
		fclose(glob_vars->file);
		free_dlistint(temp);
		exit(EXIT_FAILURE);
	}
	else
	{
		holder = temp->n;
		pop(stack, line_number);
		(*stack)->n *= holder;
	}
}

/**
 * sub - subtracts top elem from second top elems
 * @stack: pointer to stack
 * @line_number: line number of opcode
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int total = 0, counter = 0;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		temp = temp->next;
		counter++;
	}

	if (stack == NULL || (*stack)->next == NULL || counter <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	total = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);

	(*stack)->n = total;
}

/**
 * _div - div top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int total = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(glob_vars->buffer);
		fclose(glob_vars->file);
		free_dlistint(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(glob_vars->buffer);
		fclose(glob_vars->file);
		free_dlistint(*stack);
		cleanup_global_vars();
		exit(EXIT_FAILURE);
	}
	else
	{
		total = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n /= total;
	}
}

/**
 * mod - finds mod of elem at top of stack to second top elem.
 * @stack: pointer to stack
 * @line_number: number of opcode line
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int mod = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(glob_vars->buffer);
		fclose(glob_vars->file);
		free_dlistint(*stack);
		cleanup_global_vars();
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(glob_vars->buffer);
		fclose(glob_vars->file);
		free_dlistint(*stack);
		cleanup_global_vars();
		exit(EXIT_FAILURE);
	}
	else
	{
		mod = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n %= mod;
	}
}
