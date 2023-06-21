#include "monty.h"

globales_t globalvar = {NULL, NULL, NULL};

/**
 * main - entry point for the CLI program
 * @argc: count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		stderr_usage();

	globalvar.fd = fopen(argv[1], "r");
	if (globalvar.fd == NULL)
		stderr_fopen(argv[1]);

	while (getline(&globalvar.line_buf, &(size_t){0}, globalvar.fd) != -1)
	{
		if (globalvar.line_buf[0] != '#' && globalvar.line_buf[0] != '\n')
		{
			char *token = strtok(globalvar.line_buf, DELIM);
			globalvar.token2 = strtok(NULL, DELIM);
			if (token != NULL)
				get_builtin(token, &(stack_t){NULL}, ++line_number);
		}
	}

	free_dlistint(globalvar.stack);
	free(globalvar.line_buf);
	globalvar.line_buf = NULL;
	fclose(globalvar.fd);

	return EXIT_SUCCESS;
}
