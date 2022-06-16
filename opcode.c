#include "monty.h"

/**
 * _isint - checks if second argument is digit
 * @arg: argument to be checked
 * Return: 0 if digit, else 1
 */
int _isint(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * pushit - adds a new node
 * @stack: pointer to head of stack
 * @n: value to be added
 * Return: pointer to the new node, NULL if failure
 */
stack_t *pushit(stack_t **stack, const int n)
{
	stack_t *new;

	if (stack == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*stack == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else
	{
		(*stack)->prev->next = new;
		new->prev = (*stack)->prev;
		(*stack)->prev = new;
		new->next = *stack;
	}
	if (var.queue == STACK || var.stack_len == 0)
		*stack = new;
	return (new);
}

/**
 * _push - push / add an integer to stack
 * @stack: pointer to head of stack
 * @lnum: line number
 */
void _push(stack_t **stack, unsigned int lnum)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t ");
	if (arg == NULL || _isint(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", lnum);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (pushit(stack, n) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}

/**
 * _pall - print all values in stack
 * @stack: pointer to head of stack
 * @lnum: line number
 */
void _pall(stack_t **stack, unsigned int lnum)
{
	stack_t *head;

	(void)(lnum);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
			return;
	}
}
