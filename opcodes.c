#include "monty.h"

/**
 * _pint -  prints the value at the top of the stack
 * @stack: pointer to head of stack
 * @lnum: line number
 */
void _pint(stack_t **stack, unsigned int lnum)
{
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lnum);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
