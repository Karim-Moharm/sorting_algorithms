#include "sort.h"

/**
 * insertion_sort_list - insertion sort using linked list
 * @list: pointer to the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *temp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		while(curr->prev && curr->n < curr->prev->n)
		{
			/* swap operation */
			temp = curr;
			curr->prev->next = curr->next;
			if (curr->next)
				curr->next->prev = curr->prev;

			/* reduce the current pointer */
			curr = curr->prev;
			
			temp->next = curr;
			temp->prev = curr->prev;

			if (curr->prev)
				curr->prev->next = temp;
			curr->prev = temp;
			
			/** 
			 * if the node reached the head of a list
			 * update the pointer list to that node
			 */
			if (!temp->prev)
				*list = temp;
			print_list(*list);
			curr = curr->prev;
		}
		curr = curr->next;
	}

}
