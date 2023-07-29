#include "sort.h"

/**
 * hoare_partition - Hoare partition scheme using the rightmost index as pivot.
 *
 * @array: Array of integers to be sorted.
 * @low: Index in the source array that begins the partition.
 * @high: Index in the source array that ends the partition.
 * @size: Amount of elements in the array.
 *
 * Return: New index at which to start a new recursive partition.
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (true)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * hoare_quicksort_recursive - Recursively sorts an array of integers using Hoare quick sort.
 *
 * @array: Array of integers to be sorted.
 * @low: Index in the source array that begins the partition.
 * @high: Index in the source array that ends the partition.
 * @size: Amount of elements in the array.
 *
 * Return: Nothing.
 */
void hoare_quicksort_recursive(int *array, size_t low, size_t high, size_t size)
{
	size_t border;

	if (low < high)
	{
		border = hoare_partition(array, low, high, size);
		hoare_quicksort_recursive(array, low, border, size);
		hoare_quicksort_recursive(array, border + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the Hoare partition scheme.
 *
 * @array: Array of integers to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: Nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort_recursive(array, 0, size - 1, size);
}
