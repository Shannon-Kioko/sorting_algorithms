#include "sort.h"

/**
 * get_max - Get max value in an array of ints.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int maxi, i;

	for (maxi = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxi)
			maxi = array[i];
	}

	return (maxi);
}

/**
 * counting_sort - Counting sort algorithm to sort an array of ints in ascending order
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted_arr, maxi, i;

	if (array == NULL || size < 2)
		return;

	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
		return;
	maxi = get_max(array, size);
	count = malloc(sizeof(int) * (maxi + 1));
	if (count == NULL)
	{
		free(sorted_arr);
		return;
	}

	for (i = 0; i < (maxi + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (maxi + 1); i++)
		count[i] += count[i - 1];
	print_array(count, maxi + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_arr[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_arr[i];

	free(sorted_arr);
	free(count);
}
