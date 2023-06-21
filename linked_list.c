#include "monty.h"

/**
 * create_node_stackfirst - create a node stack.
 * @stack: A pointer to top and bottom stack.
 * @n: the value
 * Return: the node
 */
stack_t *create_node_stackfirst(stack_t **stack, int n)
{
	stack_t *newnode_stack = malloc(sizeof(stack_t));

	if (newnode_stack == NULL)
		stderr_malloc();

	newnode_stack->n = n;
	newnode_stack->next = *stack;
	newnode_stack->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = newnode_stack;

	*stack = newnode_stack;
	return newnode_stack;
}

/**
 * create_node_stackend - create a node stack at end.
 * @stack: A pointer to top and bottom stack.
 * @n: the value
 * Return: the node
 */
stack_t *create_node_stackend(stack_t **stack, int n)
{
	stack_t *newnode_stack = malloc(sizeof(stack_t));

	if (newnode_stack == NULL)
		stderr_malloc();

	newnode_stack->n = n;
	newnode_stack->next = NULL;

	if (*stack == NULL)
	{
		newnode_stack->prev = NULL;
		*stack = newnode_stack;
		return newnode_stack;
	}

	stack_t *temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = newnode_stack;
	newnode_stack->prev = temp;

	return newnode_stack;
}

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: pointer to the first element of the list
 * @n: integer
 * Return: the pointer to a new node at the beginning of a dlistint_t list
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
		return NULL;

	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *head;

	if (*head != NULL)
		(*head)->prev = newnode;

	*head = newnode;

	return newnode;
}
