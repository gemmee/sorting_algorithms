#include "sort.h"

/**
 * counting_sort - sorts an array of integers using Counting sort algorithm
 * @array: the array to sorted
 * @size: Number of elements in the array
 *
 * Description: The array will contain only numbers >= 0.
 * Counting sort is not a comparison sort.
 *
 * Author: Gamachu
 * Place: Mariyam. Jul 04, 2025
 */
void counting_sort(int *array, size_t size)
{
	int i, j, k, *output, *count;

	k = array[0];
	for (i = 1; i < (int)size; i++)
	{
		/* find the largest element */
		if (array[i] > k)
			k = array[i];
	}
	count = calloc(k + 1, sizeof(int));
	if (!count)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];

	print_array(count, k + 1);
	for (j = (int)size - 1; j >= 0; j--)
	{
		count[array[j]] = count[array[j]] - 1;
		output[count[array[j]]] = array[j];
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
