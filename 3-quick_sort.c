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
 * lomuto_partition - used for partitioning the array
 * @arr: array of int
 * @start: points to first element in the array (index 0)
 * @end: points to last element in the array
 * @size: size of the array
 *
 * Return: index of pivot 
 */
u_int32_t LomutoPartition(int *arr, u_int32_t start, u_int32_t end, size_t size)
{
	/* implement the algorithm by using pivot as last element */
	int pivot = arr[end];
	u_int32_t i = start;
	u_int32_t j = 0;

	for (j = 0; j < end; ++j)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[i], &arr[j]);
			print_array(arr, size);
			i++;
		}
	}
	swap(&arr[i], &arr[end]);
	return i;
}

/**
 * quickSortr_recursion - implementation of quick sort algorithm
 * by applying the partition technique to sub arrays of the array using
 * recursion
 * @arr: array of int
 * @start: points to first element in the array (index 0)
 * @end: points to last element in the array
 * @size: size of the array
 */
void quickSortr_recursion(int *arr, u_int32_t start, u_int32_t end, size_t size)
{
	u_int32_t pivot_idx = 0;

	if (start >= end)
		return;
	pivot_idx = LomutoPartition(arr, start, end, size);
	quickSortr_recursion(arr, start, pivot_idx - 1, size);
	quickSortr_recursion(arr, pivot_idx + 1, end, size);

}

/**
 * quick_sort - excute the algorithm
 * @array: array o fint to be sorted
 * @size: size of array
 */ 
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickSortr_recursion(array, 0, size - 1, size);
}
