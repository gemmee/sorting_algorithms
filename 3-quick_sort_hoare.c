#include "sort.h"

void quick_sort_recursive(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);


/**
 * quick_sort - sorts an array using the Quick sort algorithm with
 * hoare partition scheme implementation
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
    pivot_idx = hoare_partition(array, low, high, size);
    quick_sort_recursive(array, low, pivot_idx, size);
    quick_sort_recursive(array, pivot_idx + 1, high, size);
  }
}


/**
 * hoare_partition - rearranges the subarray in place using hoare partition scheme
 * @array: the array
 * @low: the lowest index of the subarray
 * @high: the highest index of the subarray
 * @size: the size of the original array (needed for printing)
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
  int i, j, pivot, temp;

  pivot = array[low];
  i = low - 1;
  j = high + 1;
  while (i < j)
  {
    do {
      i++;
    } while (array[i] < pivot);
    
    do {
      j--;
    } while (array[j] > pivot);

    if (i < j)
    {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      print_array(array, size);
    }
  }
  return (j);
}
