#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme using the rightmost index as pivot.
 *
 * @array: Array of integers to be sorted.
 * @low: Index in the source array that begins the partition.
 * @high: Index in the source array that ends the partition.
 * @size: Amount of elements in the array.
 *
 * Return: New index at which to start a new recursive partition.
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
 * lomuto_quicksort_recursive - Recursively sorts an array of integers using Lomuto quick sort.
 *
 * @array: Array of integers to be sorted.
 * @low: Index in the source array that begins the partition.
 * @high: Index in the source array that ends the partition.
 * @size: Amount of elements in the array.
 */
void lomuto_quicksort_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
    ssize_t pivot_pos;

    if (low < high)
    {
        pivot_pos = lomuto_partition(array, low, high, size);
        lomuto_quicksort_recursive(array, low, pivot_pos - 1, size);
        lomuto_quicksort_recursive(array, pivot_pos + 1, high, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Lomuto partition scheme.
 *
 * @array: Array of integers to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    lomuto_quicksort_recursive(array, 0, size - 1, size);
}
