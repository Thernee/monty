#include "monty.h"

static global_vars *instance;
/**
 * main - main function for the monty program
 * @argc: total number of arguments
 * @argv: the arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	stack_t **stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	get_input(stack, argv[1]);


	free_dlistint(*stack);
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

/**
 * get_global_vars_instance - Retrieves the global_vars instance.
 *
 * This function returns a pointer to the global_vars structure.
 * Return: A pointer to the global_vars instance.
 */
global_vars *get_global_vars_instance(void)
{
	if (instance == NULL)
	{
		instance = malloc(sizeof(global_vars));
		instance->buffer = NULL;
		instance->file = NULL;
		instance->op_args = 0;
	}
	return (instance);
}
/**
 * cleanup_global_vars - Frees the memory allocated for the global_vars
 *
 * This function frees the memory allocated for the global_vars structure.
 * frees any dynamically allocated memory within the structure
 */
void cleanup_global_vars(void)
{
	if (instance != NULL)
	{
		free(instance->buffer);

		free(instance);
		instance = NULL;
	}
}
