#include <stdio.h>
#include "your_list_header_file.h"  /* Replace "your_list_header_file.h" with the appropriate header file that defines the list_t structure. */

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	if (h == NULL)
	{
		printf("[0] (nil)\n");
		return (0);
	}

	while (h != NULL)
	{
		printf("%s ", h->str);
		h = h->next;
		count++;
	}

	printf("\n");
	return (count);
}
