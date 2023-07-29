#include "sort.h"

/**
 * sift_down - Helper function to perform the sift-down operation on a heap.
 *
 * @array: Array of integers representing the heap.
 * @size: Size of the heap.
 * @index: Index of the element to sift down.
 */
void sift_down(int *array, size_t size, size_t index)
{
    size_t max_index = index;
    size_t left_child = 2 * index + 1;
    size_t right_child = 2 * index + 2;

    if (left_child < size && array[left_child] > array[max_index])
        max_index = left_child;

    if (right_child < size && array[right_child] > array[max_index])
        max_index = right_child;

    if (max_index != index)
    {
        int temp = array[index];
        array[index] = array[max_index];
        array[max_index] = temp;

        print_array(array, size);

        sift_down(array, size, max_index);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 *
 * @array: Array of integers to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Build a max heap from the array */
    for (int i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i);

    /* Extract elements from the heap and adjust the heap */
    for (int i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        print_array(array, size);

        sift_down(array, i, 0);
    }
}
