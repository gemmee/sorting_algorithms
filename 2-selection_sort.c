#include "sort.h"

/**
 * selection_sort - sorts an array of integers using the selection
 * sort algorithm
 * @array: pointer to the array
 * @size: The number of elements in the array
 *
 * Description: print the array after each time you swap two elements
 *
 * Author: Gamachu
 * Place: et, June 03, 2025
 */
void selection_sort(int *array, size_t size)
{
  size_t i, j;
  int min_idx, temp;

  for (i = 0; i < size - 1; i++)
  {
    min_idx = i;

    for (j = i + 1; j < size; j++)
    {
      if (array[j] < array[min_idx])
        min_idx = j;
    }
    temp = array[i];
    array[i] = array[min_idx];
    array[min_idx] = temp;
    print_array(array, size);
  }
}
