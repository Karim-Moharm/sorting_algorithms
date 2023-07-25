#include "sort.h"
#include <string.h>

/**
 * max - get the max element in array
 *
 * @arr: array of integer
 * @size: size of array
 * Return: max element in array
 */
int max(int *arr, size_t size)
{
	size_t i = 0;
	int max = arr[0];

	for (i = 1; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
* counting_sort - count sort algorithm
* @array: array of int
* @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	size_t i = 0, count_size = 0;
	int max_elem = 0;
	int *count = NULL, *output = NULL;

	if (!array || size < 2)
		return;
	/* finding max element in array */
	max_elem = max(array, size);
	count_size = max_elem + 1;

	count = malloc(sizeof(int) * count_size);
	if (!count)
		return;
	/* setting all element in count to 0 */
	memset(count, 0, count_size * sizeof(*count));
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* update count array so it can store index of elements */
	for (i = 1; i < count_size; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, count_size);

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	i = size;
	while (i > 0)
	{
		i--;
		count[array[i]]--;
		output[count[array[i]]] = array[i];
	}
	/* copying element from output array to array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
