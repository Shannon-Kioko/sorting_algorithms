#include "sort.h"

/**
 * sift_down - Helper function to maintain the max heap property of a binary tree.
 *
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void sift_down(int *array, size_t size, size_t base, size_t root)
{
    size_t left_child, right_child, largest_node;

    left_child = 2 * root + 1;
    right_child = 2 * root + 2;
    largest_node = root;

    if (left_child < base && array[left_child] > array[largest_node])
        largest_node = left_child;
    
    if (right_child < base && array[right_child] > array[largest_node])
        largest_node = right_child;

    if (largest_node != root)
    {
        int_swapper(array + root, array + largest_node);
        print_array(array, size);
        sift_down(array, size, base, largest_node);
    }
}

/**
 * build_max_heap - Build a max heap from a binary tree represented by an array.
 *
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 */
void build_max_heap(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    for (int i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, size, i);
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

    build_max_heap(array, size);

    for (int i = size - 1; i > 0; i--)
    {
        int_swapper(array, array + i);
        print_array(array, size);
        sift_down(array, size, i, 0);
    }
}
