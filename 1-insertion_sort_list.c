#include "sort.h"

/**
 * insertion_sort_list - insertion sort using linked list
 * @list: pointer to the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = (*list)->next;

	while (curr)
	{
		while(curr->prev && curr->n < curr->prev->n)
		{
			/* swap operation */
			curr->prev->next = curr->next;
			if (curr->next)
				curr->next->prev = curr->prev;
			

		}
	}

}
