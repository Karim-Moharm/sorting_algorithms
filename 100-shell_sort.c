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
	int gap = 1;

	if (!array || size < 2)
		return;

	while (gap < size / 3)
		gap = (gap * 3) + 1;


}
