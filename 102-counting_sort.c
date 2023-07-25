#include "sort.h"
#include <string.h>

/**
* counting_sort - count sort algorithm
* @array: array of int
* @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	size_t i = 0;
	int max = array[0];
	int count_size = 0;
	int *count = NULL;

	/* finding max element in array */
	for (i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	count_size = max + 1;

	count = malloc(sizeof(int) * count_size);
	print_array(count, count_size);
	/* setting all element in count to 0 */
	memset(count, 0, count_size * sizeof(*count));
	print_array(count, count_size);
	printf("\n");

	for (i = 0; i < size; i++)
		;


}
