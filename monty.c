#include "monty.h"

global_m globm;
void set_global(void);

/**
 * main -  monty interpreter
 * @ac: command line arguments count
 * @av: command line arguments array of strings
 *
 * Return: 0 if success
 */
int main(int ac, char **av)
{
	char *buff = NULL, *dlim = " \n\t", *optok = NULL;
	size_t buff_size = 0;
	ssize_t line_size;
	FILE *fp;

	if (ac != 2)
		dprintf(2, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	fp  = fopen(av[1], "r");
	if (!fp)
	{
		dprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	globm.fp = fp;
	set_global();
	line_size = getline(&buff, &buff_size, globm.fp);
	globm.gbuff = buff;
	while (line_size >= 0)
	{
		globm.line_number += 1;
		optok = strtok(buff, dlim);

		if (optok && optok[0] != '#')
		{
			globm.n = strtok(NULL, dlim);
			get_opcode(optok);
		}
		line_size = getline(&buff, &buff_size, globm.fp);
		optok = NULL, globm.n = NULL;
	}
	exit_op();
	return (0);
}

/**
 * set_global - defines global variables
 *
 * Return: No return
 */
void set_global(void)
{
	globm.mode = 0;
	globm.gbuff = NULL;
	globm.n = NULL;
	globm.head = NULL;
	globm.line_number = 0;
}
