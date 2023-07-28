#include <stdlib.h>
#include "lists.h"

/**
 * get_list_length - Returns the number of elements in a linked list.
 * @h: Pointer to the list_t list.
 *
 * Return: Number of elements in h.
 */
size_t get_list_length(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return count;
}
