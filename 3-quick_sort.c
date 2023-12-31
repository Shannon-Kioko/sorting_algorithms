#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme using the rightmost index as pivot.
 *
 * @array: Array of integers to be sorted.
 * @low: Index in source array beginning the partition.
 * @high: Index in source array ending the partition.
 * @size: Amount of elements in the array.
 *
 * Return: New index to start a new recursive partition.
 */
int lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot, temp;
    size_t i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    if (i + 1 != high)
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * recursive_lomuto_quicksort - sorts an array of integers using recursively using Lomuto quick sort.
 *
 * @array: Array of integers to be sorted.
 * @low: Index in source array beginning the partition.
 * @high: Index in the source array ending the partition.
 * @size: Amount of elements in the array.
 */
void recursive_lomuto_quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
    ssize_t pivot_pos;

    if (low < high)
    {
        pivot_pos = lomuto_partition(array, low, high, size);
        recursive_lomuto_quicksort(array, low, pivot_pos - 1, size);
        recursive_lomuto_quicksort(array, pivot_pos + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Lomuto partition scheme.
 *
 * @array: Arr of integers to be sorted.
 * @size: Numof elements in the array.
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    recursive_lomuto_quicksort(array, 0, size - 1, size);
}
