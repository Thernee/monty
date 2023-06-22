#include "monty.h"

global_vars *glob_vars = NULL;

void initializeGlobals(void)
{
	glob_vars = malloc(sizeof(global_vars));
	glob_vars->buffer = NULL;
	glob_vars->file = NULL;
	glob_vars->op_args = 0;
}

void cleanupGlobals(void)
{
	if (glob_vars != NULL)
	{
		free(glob_vars);
		glob_vars = NULL;
	}
}
