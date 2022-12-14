#include "monty.h"

/**
 * _isnumber - checks if a string is composed of numbers
 * @s: string
 *
 * Return: 1 if string has only numbers, 0 if not
 */
int _isnumber(char *s)
{
	if (!s)
		return (0);

	if (*s == '-')
		s++;

	for (; *s; s++)
		if (!isdigit(*s))
			return (0);
	return (1);
}
