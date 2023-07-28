#include "sort.h"
/**
 * swap - swaps two input integer vals
 * @xp: First int parameter
 * @yp: First int parameter
**/

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/**
 * bubble_sort - function to bubble sort
 *
 * @array: array to be sorted
 * @size: size of array
**/
void bubble_sort(int *array, size_t size)
{
	int i, j, k;

	for (i = 0; i < (int)size - 1; i++)
	{
		for (j = 0; j < (int)size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				/** Print the array after each swap **/
				for (k = 0; k < (int)size; k++)
					printf("%u ", array[k]);
				printf("\n");
			}
		}
	}
}
