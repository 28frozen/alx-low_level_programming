#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all the elements of a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t num_nodes = 0;
	const listint_t *current_node = h;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
		num_nodes++;
	}

	return (num_nodes);
}
