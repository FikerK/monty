#include "monty.h"

/**
 * free_lptr - frees line pointer
 * @status: exit status
 * @arg: line pointer
 */
void free_lptr(int status, void *arg)
{
	char **lptr = arg;

	(void)status;
	if (*lptr != NULL)
		free(*lptr);
}

/**
 * free_stack - frees stack
 * @status: exit status
 * @arg: pointer to stack
 */
void free_stack(int status, void *arg)
{
	stack_t **stack;
	stack_t *next;

	(void)status;

	stack = (stack_t **)arg;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.stack_len = 0;
}

/**
 * fptr_close - close file
 * @status: exit status
 * @arg: file pointer
 */
void fptr_close(int status, void *arg)
{
	FILE *fptr;

	(void)status;
	fptr = (FILE *) arg;
	fclose(fptr);
}
