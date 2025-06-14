#include "sort.h"

void quick_sort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);


/**
 * quick_sort - sorts an array using the Quick sort algorithm with
 * Lomuto partition scheme implementation
 * @array: the array to be sorted
 * @size: Number of elements in the array
 *
 * Description: print the array after each time you swap two elements
 *
 * Author: Gamachu
 * Place: et, Jun 03, 2025
 */
void quick_sort(int *array, size_t size)
{
  if (!array || size < 2)
    return;
  quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - helper function that recursively sorts the array
 * @array: the array
 * @low: the lowest index of the array
 * @high: the highest index of the array
 * @size: the size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
  int pivot_idx;

  if (low < high)
  {
    pivot_idx = lomuto_partition(array, low, high, size);
    quick_sort_recursive(array, low, pivot_idx - 1, size);
    quick_sort_recursive(array, pivot_idx + 1, high, size);
  }
}


/**
 * lomuto_partition - rearranges the subarray in place using lomuto partition scheme
 * @array: the array
 * @low: the lowest index of the subarray
 * @high: the highest index of the subarray
 * @size: the size of the original array (needed for printing)
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
  int i, j, pivot, temp;

  pivot = array[high];
  i = low - 1;
  for (j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i = i + 1;
      if (i != j)
      {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        print_array(array, size);
      }
    }
  }
  if ((i + 1) != high)
  {
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);
  }
  
  return (i + 1);
}
