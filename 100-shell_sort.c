#include "sort.h"

int *generate_knuth_sequence(size_t size, int *count);

/**
 * shell_sort - sorts an array using the shell sort algorithm using
 * the Knuth sequence n+1 = n*3 + 1 i.e., (1, 4, 13, ...)
 * @array: the array
 * @size: Number of elements in the array
 *
 * Author: Gamachu
 * Place: et, Jun 03, 2025
 */
void shell_sort(int *array, size_t size)
{
  int j, h, count, temp, gap, *gaps;
  size_t i;

  if (!array || size < 2)
    return;
  
  gaps = generate_knuth_sequence(size, &count);  

  for (h = count - 1; h >= 0; h--)
  {
    gap = gaps[h];

    for (i = gap; i < size; i++)
    {
      temp = array[i];
      j = i;
      while (j >= gap && array[j - gap] > temp)
      {
        array[j] = array[j - gap];
        j -= gap;
      }
      array[j] = temp;
    }
    print_array(array, size);
  }

  free(gaps);
}


/**
 * generate_knuth_sequence - generates the knuth sequence and sets the value of count
 * @size: the size of the original array
 * @count: the size of knuth_arr
 *
 * Return: pointer to the knuth_arr
 */
int *generate_knuth_sequence(size_t size, int *count)
{
  size_t h = 1;
  int *knuth_arr;
  int c = 0;

  /* First, count how many gaps are needed */
  while (h < size)
  {
    c++;
    h = h * 3 + 1;
  }
  h = (h - 1) / 3; /* undo one unwanted step */

  /* allocate the exact size */
  knuth_arr = malloc(sizeof(int) * c);
  if (!knuth_arr)
    return NULL;

  *count = c; /* set the number of elements */
  while (h > 0)
  {
    knuth_arr[--c] = h;
    h = (h - 1) / 3;
  }

  return knuth_arr;
}
