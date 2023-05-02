#include "lists.h"

/**
* listint_len - Returns THE Numbers Of Element Of Linked Lists
* @h: linked list of type listint_t to traverse
*
* Return: number of nodes
*/

size_t listint_len(const listint_t *h)

{
	size_t num = 0;

	while (h)
	{
		num++;
		h = h->next;
	}

	return (num);
}
