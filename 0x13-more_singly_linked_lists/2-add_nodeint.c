#include "lists.h"

/**
* add_nodeint - Add a New Node To The Beginning Of The Linked List
* @head: pointer to the first node in the list
* @n: data to insert in that new node
*
* Return: pointer to the New Node, or NULL if it fails
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
