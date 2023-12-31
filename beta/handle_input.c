#include "monty.h"

/**
 * get_input - gets input from the monty file and processes it
 *
 * @stack: The stack to perform actions on
 * @filename: name of the file containing opcode and its args
 *
 * return: nothing
 */
void get_input(stack_t **stack, char *filename)
{
	size_t n = 0;
	exect_instruct fptr;
	char *input;
	int count = 1;

	glob_vars->file = fopen(filename, "r");
	if (glob_vars->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		cleanupGlobals();
		exit(EXIT_FAILURE);
	}

	while (getline(&glob_vars->buffer, &n, glob_vars->file) != -1)
	{
		input = line_split(glob_vars->buffer, count);
		if (input == NULL || input[0] == '#')
		{
			count++;
			continue;
		}

		fptr = call_func(input);
		if (fptr == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count, input);
			cleanupGlobals();
			exit(EXIT_FAILURE);
		}
		fptr(stack, count);
		count++;
	}

	if (fclose(glob_vars->file) == -1)
	{
		cleanupGlobals();
		exit(-1);
	}
	cleanupGlobals();
}

/**
 * line_split - splits opcode file content into lines
 *
 * @input: Content gotten from opcode file
 * @count: line count corresponding to 'input'
 * Return: opcode on success, NULL otherwise
 */
char *line_split(char *input, int count)
{
	char *command, *arg;

	command = strtok(input, "\n");
	if (command == NULL)
		return (NULL);

	if (strcmp(command, "push") != 0)
		return (command);

	arg = strtok(NULL, "\n ");

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		cleanupGlobals();
		exit(EXIT_FAILURE);
	}

	if (check_num(arg))
		glob_vars->op_args = atoi(arg);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		cleanupGlobals();
		exit(EXIT_FAILURE);
	}

	return (command);
}

/**
 * call_func - calls appropriate function to handle opcode
 *
 * @command: The opcode
 * Return: Appropriate function to handle opcode
 */
exect_instruct call_func(char *command)
{
	int curr = 0;

	instruction_t action[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};

	while (action[curr].f != NULL && strcmp(action[curr].opcode, command) != 0)
	{
		curr++;
	}

	return (action[curr].f);
}

/**
 * check_num - checks if a given string is a number or not
 *
 * @str: The string to be checked
 * Return: True if str is a number, False otherwise
 */
int check_num(char *str)
{
	char *endptr;

	if (str == NULL)
		return (0);

	strtol(str, &endptr, 10);

	if (*endptr == '\0')
		return (1);

	return (0);
}

