#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array.
 * @item1: Index of the first element to swap.
 * @item2: Index of the second element to swap.
 */
void swap_quicksort(int *array, ssize_t item1, ssize_t item2)
{
    int tmp;

    tmp = array[item1];
    array[item1] = array[item2];
    array[item2] = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme implementation for quicksort.
 * @array: The array to be sorted.
 * @first: The first index of the array to be considered.
 * @last: The last index of the array to be considered.
 * @size: The size of the array.
 *
 * Return: The position of the last element sorted.
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
    int pivot = array[last];
    ssize_t current = first, finder;

    for (finder = first; finder < last; finder++)
    {
        if (array[finder] < pivot)
        {
            if (array[current] != array[finder])
            {
                swap(array, current, finder);
                print_array(array, size);
            }
            current++;
        }
    }
    if (array[current] != array[last])
    {
        swap(array, current, last);
        print_array(array, size);
    }
    return (current);
}

/**
 * quicksort_recursive - Recursive function to implement quicksort algorithm.
 * @array: The array to be sorted.
 * @first: The first index of the array to be considered.
 * @last: The last index of the array to be considered.
 * @size: The size of the array.
 */
void quicksort_recursive(int *array, ssize_t first, ssize_t last, size_t size)
{
    ssize_t position = 0;

    if (first < last)
    {
        position = lomuto_partition(array, first, last, size);

        quicksort_recursive(array, first, position - 1, size);
        quicksort_recursive(array, position + 1, last, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;
    
    quicksort_recursive(array, 0, size - 1, size);
}
