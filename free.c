#include "monty.h"

/**
 * free_stack - Frees a stack_t stack.
 * @my_stack: Pointer to the first element of the stack
 *
 * Return: No return
 */
void free_stack(stack_t *my_stack)
{
	stack_t *auxiliary = NULL;
	stack_t *temporary = NULL;

	temporary = my_stack;
	while (temporary != NULL)
	{
		auxiliary = temporary->next;
		free(temporary);
		temporary = auxiliary;
	}
	my_stack = NULL;
}

/**
 * free_resources - Frees resources used by the program.
 *
 * Return: No return
 */
void free_resources(void)
{
	fclose(globalvar.my_file);
	free(globalvar.buffer);
}
