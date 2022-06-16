#include "monty.h"

var_t var;

/**
 * main - interpreter for Monty ByteCodes Files
 * @ac: number of arguments
 * @av: pointer opcode
 * Return: 0
 */
int main(int ac, __attribute__((unused)) char **av)
{
	FILE *fptr = NULL;
	stack_t *stack = NULL;
	unsigned int lnum = 0;
	char *lptr = NULL;
	char *op = NULL;
	size_t n = 0;

	var.queue = 0;
	var.stack_len = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(av[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	on_exit(free_lptr, &lptr);
	on_exit(free_stack, &stack);
	on_exit(fptr_close, fptr);
	while (getline(&lptr, &n, fptr) != -1)
	{
		lnum++;
		op = strtok(lptr, "\n\t ");
		if (op != NULL && op[0] != '#')
			_ops(op, &stack, lnum);
	}
	exit(EXIT_SUCCESS);
}
