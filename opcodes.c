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

/**
 * _pop -  removes the top element of the stack
 * @stack: pointer to head of stack
 * @lnum: line number
 */
void _pop(stack_t **stack, unsigned int lnum)
{
	stack_t *pop = *stack;

	if (var.stack_len == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lnum);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.stack_len != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	var.stack_len--;
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @lnum: line number
 */
void _swap(stack_t **stack, unsigned int lnum)
{
	stack_t *next;

	if (var.stack_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", lnum);
		exit(EXIT_FAILURE);
	}
	if (var.stack_len == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	next = (*stack)->next;
	next->prev = (*stack)->prev;
	(*stack)->prev->next = next;
	(*stack)->prev = next;
	(*stack)->next = next->next;
	next->next->prev = *stack;
	next->next = *stack;
	*stack = next;
}
