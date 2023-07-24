#include "sort.h"

/**
 * swap_nodes - function used to swap node with its previous node
 * @node1: A pointer to the first node to be swapped.
 * @node2:  A pointer to the second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
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

	if (node1->prev == NULL)
		*list = node1;
}

/**
 * insertion_sort_list - insertion sort using linked list
 * @list: pointer to the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *tmp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	
	curr = (*list)->next;

	while (curr)
	{
		tmp = curr;
		curr = curr->next;

		while (tmp->n < tmp->prev->n && tmp->prev)
		{
			swap_nodes(list, tmp->prev, tmp);
			print_list(*list);
		}
	}
}
