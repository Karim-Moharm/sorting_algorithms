#include "sort.h"
#include <stdbool.h>

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
 * bubble_sort -  sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	bool swapped = false;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}
		/**
		 * in case no element in 1'st iteration swapped
		 * the array is already sorted
		 */
		if (swapped == false)
			break;
	}

}
