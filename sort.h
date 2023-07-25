#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void swap(int *num1, int *num2);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void insertion_sort_list(listint_t **list);

int LomutoPartition(int *arr, int start, int end, size_t size);
void quickSortr_recursion(int *arr, int start, int end, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void shell_sort(int *array, size_t size);
int max(int *arr, size_t size);
void counting_sort(int *array, size_t size);
#endif
