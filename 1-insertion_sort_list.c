#include "sort.h"


void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2 || node1 == node2)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	
	/* address of node1 in node2 and address of node2 in node1 */
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - insertion sort using linked list
 * @list: pointer to the doubly linked list
 */
/*void insertion_sort_list(listint_t **list)
{
	;
}*/
