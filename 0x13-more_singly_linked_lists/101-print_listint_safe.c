#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	const listint_t *current = head;
	const listint_t *check;
	size_t i;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		nodes++;

		check = head;
		for (i = 0; i < nodes; i++)
		{
			if (check == current->next)
			{
				printf("-> [%p] %d\n", (void *)current->next, current->next->n);
				return (nodes);
			}
			check = check->next;
		}

		current = current->next;
	}

	return (nodes);
}
