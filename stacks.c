#include "monty.h"

/**
 * create_node_stack - Create a node stack.
 * @stack: A pointer to top and bottom stack.
 *
 * Return: EXIT_SUCCESS on success, or appropriate error code.
 */
int create_node_stack(stack_t **stack)
{
	stack_t *p = malloc(sizeof(stack_t));

	if (p == NULL)
		stderr_malloc();
	p->n = STACK;
	p->prev = NULL;
	p->next = NULL;

	*stack = p;

	return (EXIT_SUCCESS);
}

/**
 * free_node_stack - Frees a stack_t stack.
 * @stack: A pointer to top and bottom stack.
 */
void free_node_stack(stack_t **stack)
{
	stack_t *temp_node;

	while (*stack)
	{
		temp_node = (*stack)->next;
		free(*stack);
		*stack = temp_node;
	}
}

/**
 * check_opcode - Checks if stack is STACK or QUEUE.
 * @stack: A pointer to top and bottom stack.
 *
 * Return: The value of STACK or QUEUE, or 2 if invalid.
 */
int check_opcode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	else
		return (2);
}
