#include "monty.h"

/**
 * _mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int count = 0, tmpn;

	while (tmp)
		tmp = tmp->next, count++;
	if (count < 2)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	tmpn = (*stack)->n;
	delete_node_index(stack, 0);

	if (tmpn == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	(*stack)->n %= tmpn;
}
/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int chr;

	if (!stack || !(*stack))
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	chr = tmp->n;
	if (chr < 32 || chr > 126)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		exit_op();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", tmp->n);

}
/**
 * _pstr - prints the string starting at the top of the stack, followed
 * by a new line
 * top element of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int chr;

	(void) line_number;
	while (stack && tmp)
	{
		chr = tmp->n;
		if (chr < 1 || chr > 127)
			break;
		printf("%c", chr);
		tmp = tmp->next;
	}
	printf("\n");

}
/**
 * _rotl - rotates the stack to the top
 * element of the stack
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *last = *stack, *lastcp;

	(void) line_number;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	while (last->next)
		last = last->next;

	*stack = tmp->next;
	(*stack)->prev = tmp->prev;

	lastcp = last;

	tmp->next = lastcp->next;
	last->next = tmp;
	tmp->prev = last;


}
/**
 * _rotr - rotates the stack to the bottom
 * of the stack.
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack, *last = *stack, *prelast;

	(void) line_number;

	if (!stack || !(*stack) || !(*stack)->next)
		return;

	while (last->next)
		last = last->next;

	prelast = last->prev;
	prelast->next = last->next;

	last->next = tmp;
	last->prev = tmp->prev;
	tmp->prev = last;

	*stack = last;
}
