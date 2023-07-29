#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array.
 * @array: Pointer to original array.
 * @left: Pointer to left subarray.
 * @sizo_left: Size of the left subarray.
 * @right: Pointer to right subarray.
 * @sizo_right: Size of right subarray.
 *
 * Return: Nothing.
 */
void merge(int *array, int *left, size_t sizo_left, int *right, size_t sizo_right)
{
	size_t i = 0, j = 0, k = 0;
	int *tempo = malloc((sizo_left + sizo_right) * sizeof(int));

	if (tempo == NULL)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, sizo_left);
	printf("[right]: ");
	print_array(right, sizo_right);

	while (i < sizo_left && j < sizo_right)
	{
		if (left[i] <= right[j])
		{
			tempo[k] = left[i];
			i++;
		}
		else
		{
			tempo[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < sizo_left)
	{
		tempo[k] = left[i];
		i++;
		k++;
	}

	while (j < sizo_right)
	{
		tempo[k] = right[j];
		j++;
		k++;
	}

	for (i = 0; i < sizo_left + sizo_right; i++)
		array[i] = tempo[i];

	printf("[Done]: ");
	print_array(array, sizo_left + sizo_right);

	free(tempo);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t midd = size / 2;
		size_t sizo_left = midd;
		size_t sizo_right = size - midd;
		int *left = array;
		int *right = array + midd;

		merge_sort(left, sizo_left);
		merge_sort(right, sizo_right);
		merge(array, left, sizo_left, right, sizo_right);
	}
}
