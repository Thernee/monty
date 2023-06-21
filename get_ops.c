#include "monty.h"
#include <stdbool.h>

/**
 * get_builtin - Parses the instruction with the function.
 * @token: Pointer to the instruction token
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 *
 * Return: Returns the function
 */
int get_builtin(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_built[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"mul", mul},
		{"div", div_m},
		{"pchar", pchar},
		{"mod", mod_m},
		{"\n", nop},
		{" ", nop},
		{"\t", nop},
		{"pstr", pstr_t},
		{"rotl", rotrl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	bool flag = false;

	if (stack == NULL || token == NULL)
		return 0;

	for (int i = 0; op_built[i].opcode; i++)
	{
		if (strcmp(token, op_built[i].opcode) == 0)
		{
			flag = true;
			op_built[i].f(stack, line_number);
			break;
		}
	}

	if (!flag)
		stderr_unknown(token, line_number);

	return 0;
}
