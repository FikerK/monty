#include "monty.h"

/**
 * _ops - valid opcodes
 * @op: opcode to be checked
 * @stack: pointer to head stack
 * @lnum: line number
 */
void _ops(char *op, stack_t **stack, unsigned int lnum)
{
	size_t i;
	instruction_t valid_ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};

	for (i = 0; valid_ops[i].opcode != NULL; i++)
	{
		if (strcmp(valid_ops[i].opcode, op) == 0)
		{
			valid_ops[i].f(stack, lnum);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", lnum, op);
	exit(EXIT_FAILURE);
}
