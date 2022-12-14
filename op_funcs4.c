#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO).
 * This is the default behavior of the program.
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	globm.mode = 0;
}
/**
 * _queue -  sets the format of the data to a queue (FIFO).
 * @stack: Pointer to head of stack (or queue)
 * @line_number: Current line number
 *
 * Return: No Return
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	globm.mode = 1;
}
