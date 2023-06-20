#include "monty.h"

/**
 * main - main function for the monty program
 * @ac: total number of arguments
 * @av: the arguments
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*handle input*/

	/*free stack here*/
	return (0);
}
