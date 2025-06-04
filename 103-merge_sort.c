#include "sort.h"
#include <stdio.h>

void split_merge(int *array, int *buffer, size_t start, size_t end);
void merge(int *array, int *buffer, size_t start, size_t mid, size_t end);

/**
 * merge_sort - sorts an array of integers in ascending order
 *              using the Merge sort algorithm (top-down)
 * @array: the array to sort
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *buffer;

    if (!array || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (!buffer)
        return;

    split_merge(array, buffer, 0, size);
    free(buffer);
}

/**
 * split_merge - splits the array and merges recursively
 * @array: original array
 * @buffer: temporary buffer for merging
 * @start: starting index
 * @end: ending index (exclusive)
 */
void split_merge(int *array, int *buffer, size_t start, size_t end)
{
    size_t mid;

    if (end - start < 2)
        return;

    mid = (start + end) / 2;

    split_merge(array, buffer, start, mid);
    split_merge(array, buffer, mid, end);
    merge(array, buffer, start, mid, end);
}

/**
 * merge - merges two sorted subarrays
 * @array: original array
 * @buffer: temporary buffer
 * @start: starting index
 * @mid: middle index
 * @end: ending index (exclusive)
 */
void merge(int *array, int *buffer, size_t start, size_t mid, size_t end)
{
    size_t i = start, j = mid, k = start;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + start, mid - start);
    printf("[right]: ");
    print_array(array + mid, end - mid);

    while (i < mid && j < end)
    {
        if (array[i] <= array[j])
            buffer[k++] = array[i++];
        else
            buffer[k++] = array[j++];
    }
    while (i < mid)
        buffer[k++] = array[i++];
    while (j < end)
        buffer[k++] = array[j++];

    for (i = start; i < end; i++)
        array[i] = buffer[i];

    printf("[Done]: ");
    print_array(array + start, end - start);
}

