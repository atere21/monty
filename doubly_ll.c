#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list.
 * @head: pointer to head of doubly linked list
 * @n: numeric value wanted in new node
 *
 * Return: address to the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		exit_op();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}
/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list.
 * @head: pointer to head of doubly linked list
 * @n: numeric value wanted in new node
 *
 * Return: address to the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node, *tmp = *head;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(2, "Error: malloc failed\n");
		exit_op();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	if (!(*head))
	{
		new_node->prev = NULL, new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	while (tmp->next)
		tmp = tmp->next;
	new_node->prev = tmp;
	new_node->next = NULL;
	tmp->next = new_node;
	return (new_node);
}
/**
 * delete_node_index - deletes the node at index
 * @head: pointer to head of doubly linked list
 * @index: index to look for
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_node_index(stack_t **head, unsigned int index)
{
	stack_t *tmpcount = *head, *tmp1 = *head, *tmp2, *tmp3;
	unsigned int count = 0;

	if (!head || !(*head))
		return (-1);
	while (tmpcount)
		tmpcount = tmpcount->next, count++;
	if (index > (count - 1))
		return (-1);
	if (index == 0)
	{
		tmp1 = tmp1->next;
		free(*head);
		*head = tmp1;
		if (*head)
			(*head)->prev = NULL;
		return (1);
	}
	for (count = 0; count < index; count++)
		tmp2 = tmp1, tmp1 = tmp1->next;

	tmp2->next = tmp1->next;
	tmp3 = tmp1->next;
	if (tmp3)
		tmp3->prev = tmp2;
	free(tmp1);
	return (1);
}
/**
 * free_stack_t - function that frees a stack_t list.
 * @head: head of doubly linked list
 *
 * Return: No return
 */
void free_stack_t(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
