#include "lists.h"
#include <stdio.h>

/**
 * count_nodes - Counts the number of nodes in a linked list
 * @head: A pointer to the head of the listint_t list
 *
 * Return: The number of nodes in the list.
 */
size_t count_nodes(const listint_t *head)
{
	size_t count = 0;

	while (head)
	{
		count++;
		head = head->next;
	}

	return (count);
}

/**
 * is_infinite - Checks if a linked list is infinite (looped)
 * @head: A pointer to the head of the listint_t list
 *
 * Return: 1 if the list is infinite, 0 otherwise.
 */
int is_infinite(const listint_t *head)
{
	const listint_t *tortoise, *hare;

	tortoise = head;
	hare = head;

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
			return (1);
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;

	if (is_infinite(head))
	{
		printf("-> [%p] %d\n", (void *)head, head->n);
		return (1);
	}

	count = count_nodes(head);
	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		count--;
	}

	return (count);
}
