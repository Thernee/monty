#include "monty.h"

/**
 * array_len - Calculates the length of an array token.
 *
 * Return: Length of the token.
 */
unsigned int array_len(void)
{
	unsigned int token_len = 0;

	while (globalvar.token2[token_len])
		token_len++;
	return (token_len);
}

/**
 * tokerr - Sets the last element of instructions as an error code.
 * @error_status: Integer representing the error status.
 */
void tokerr(int error_status)
{
	unsigned int token_len = array_len();
	char *exit_str = get_int(error_status);
	char *new_token = malloc(sizeof(char *) * (token_len + 2));

	if (!new_token)
	{
		stderr_malloc();
		return;
	}

	if (!globalvar.token2)
	{
		free(new_token);
		stderr_malloc();
		return;
	}

	for (unsigned int i = 0; i < token_len; i++)
		new_token[i] = globalvar.token2[i];

	free(globalvar.token2);
	globalvar.token2 = new_token;

	if (!exit_str)
	{
		stderr_malloc();
		return;
	}
}
