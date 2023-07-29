#include <stdio.h>

/**
 * swap - swaps two input integer values
 * @xp: First int parameter
 * @yp: First int parameter
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * selection_sort - function to sort an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			/** Print the array after each swap **/
				print_array(array, size);
			printf("\n");
		}
	}
}
