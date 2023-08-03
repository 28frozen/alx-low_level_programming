#include "lists.h"

/**
 * reverse_listint_rec - reverses a linked list recursively
 * @current: pointer to the current node
 * @prev: pointer to the previous node
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint_rec(listint_t *current, listint_t *prev)
{
	listint_t *next;

	if (!current)
		return (prev);

	next = current->next;
	current->next = prev;

	return (reverse_listint_rec(next, current));
}

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	if (!head || !*head)
		return (NULL);

	*head = reverse_listint_rec(*head, NULL);

	return (*head);
}
