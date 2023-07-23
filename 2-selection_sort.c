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
 * selection_sort - sorting an array in ascending order
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t min_idx = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		swap(&array[i], &array[min_idx]);
		print_array(array, size);
	}
}
