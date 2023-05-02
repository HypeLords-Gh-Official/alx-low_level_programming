#include "lists.h"

/**
* pop_listint - Delete The HEAD NODE Of The Linked List
* @head: Pointer To The First Element In The Linked List
*
* Return: The Data Inside The Elements Deleted,
* or 0 if the list is empty
*/

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}
