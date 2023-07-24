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
 * shell_sort - sorting array in ascending order using Knuth sequence
 * @array: integer array
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i = 0, j = 0;
	int temp;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;


	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && temp < array[j - gap])
			{
				swap(&array[j - gap], &array[j]);
				j -= gap;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
