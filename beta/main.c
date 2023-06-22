#include "monty.h"

/**
 * main - main function for the monty program
 * @argc: total number of arguments
 * @argv: the arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	stack_t *stack;

	initializeGlobals();
	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		cleanupGlobals();
		exit(EXIT_FAILURE);
	}

	get_input(&stack, argv[1]);


	free_dlistint(stack);
	cleanupGlobals();
	return (0);
}

/**
 * free_dlistint - frees a dlistint_t list
 *
 * @head: head of the list
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *holder, *temp;

	holder = head;
	while (holder != NULL)
	{
		temp = holder->next;
		free(holder);
		holder = temp;
	}
}
