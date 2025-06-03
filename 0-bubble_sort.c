#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array using Bubble sort algorithm
 * @array - the array to be sorted
 * @size - the size of the array
 *
 * Author: Gamachu
 * Place: Mariyam, Burayu
 * Date: June 01, 2025
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;

    for (i = 1; i < size; i++)
    {
	for (j = 0; j < size - i; j++)
	{
	    int temp;

	    if (array[j] > array[j + 1])
	    {
	        temp = array[j];
	        array[j] = array[j + 1];
	        array[j + 1] = temp;
	        print_array(array, size);
	    }
        }
    }
}


