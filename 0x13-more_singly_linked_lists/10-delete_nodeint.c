#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp, *current;

	if (!head || *head == NULL)
		return (-1);

	if (index == 0)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
		return (1);
	}

	temp = *head;
	while (temp && i < index - 1)
	{
		temp = temp->next;
		i++;
	}

	if (!temp || !(temp->next))
		return (-1);

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
