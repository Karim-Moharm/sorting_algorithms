#include "sort.h"

/**
 * swap - swap two numbers
 * @num1: pointer to first number
 * @num2: pointer to second number
 */
void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * HoarePartition - used for partitioning the array
 * @arr: array of int
 * @low: index 0 of array
 * @upper: last index of array
 * @size: size of the array
 *
 * Return: index of pivot
 */
int HoarePartition(int *arr, int low, int upper, size_t size)
{
	int pivot = arr[upper];
	int start = low - 1;
	int end = upper + 1;

	while (start < end)
	{
		do {
			start++;
		} while (arr[start] < pivot);

		do {
			end--;
		} while (arr[end] > pivot);

		/* swap only in case start still less than end */
		if (start < end)
		{
			swap(&arr[start], &arr[end]);
			print_array(arr, size);
		}
	}
	return (start);
}

/**
 * quickSort_recursion - implementation of quick sort algorithm
 * by applying the partition technique to sub-arrays of the array using
 * recursion
 *
 * @arr: array of integers
 * @start: points to first element in the array (index 0)
 * @end: points to last element in the array
 * @size: size of the array
 */
void quickSort_recursion(int *arr, int start, int end, size_t size)
{
	int pivot_idx = 0;

	if (start >= end)
		return;
	pivot_idx = HoarePartition(arr, start, end, size);
	quickSort_recursion(arr, start, pivot_idx - 1, size);
	quickSort_recursion(arr, pivot_idx, end, size);

}

/**
 * quick_sort_hoare - excute the algorithm
 * @array: array of int to be sorted
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickSort_recursion(array, 0, size - 1, size);
}
