#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * get_opcode - obtains the corresponding opcode and calls func
 * @opcode: string of opcode to be evaluated
 *
 * Return: O on success, or possible exit if
 * invalid instruction is given
 */
int get_opcode(char *opcode)
{
	int i;
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode && opcode; i++)
		if (!strcmp(opcode, ops[i].opcode))
		{

			ops[i].f(&(globm.head), globm.line_number);
			return (0);
		}

	dprintf(2, "L%d: unknown instruction %s\n",
		globm.line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * exit_op - performs exit operations (free/close)
 * Return: No Return
 */
void exit_op(void)
{
	free(globm.gbuff), fclose(globm.fp);
	free_stack_t(globm.head);
}
