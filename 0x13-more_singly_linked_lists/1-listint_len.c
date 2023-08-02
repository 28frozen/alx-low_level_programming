#include "lists.h"

/**
 * list_len - Returns the number of elements in a linked list.
 * @h: Pointer to the listint_t list.
 *
 * Return: Number of elements in h.
 */
size_t list_len(const listint_t *h)
{
	size_t n = 0;
	const listint_t *current_node = h;

	while (current_node)
	{
		n++;
		current_node = current_node->next;
	}

	return (n);
}
