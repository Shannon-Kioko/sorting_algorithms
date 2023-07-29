/**

 * partitionLomuto - Lomuto partition scheme using the rightmost index as pivot.
 * @arr: Array of integers to be sorted.
 * @startIndex: Index in the source array that begins the partition.
 * @endIndex: Index in the source array that ends the partition
 * @numElements: Amount of elements in the array.
 * Return: New index at which to start a new recursive partition.
**/

int partitionLomuto(int *arr, size_t startIndex, size_t endIndex, size_t numElements)
{
	int pivot, temp;
	size_t i, j;

	pivot = arr[endIndex];
	i = startIndex - 1;

	for (j = startIndex; j < endIndex; j++)
		{
			if (arr[j] <= pivot)
			{
				i++;
				if (i != j)
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
					print_array(arr, numElements);
				}
			}
		}

	if (i + 1 != endIndex)
	{
		temp = arr[i + 1];
		arr[i + 1] = arr[endIndex];
		arr[endIndex] = temp;
		print_array(arr, numElements);
	}
	
	return (i + 1);
}

/**
 * quickSortLomutoRecursive - Recursively sorts an array of integers using Lomuto quick sort.
 * @arr: Array of integers to be sorted.
 * @lowIndex: Index in the source array that begins the partition.
 * @highIndex: Index in the source array that ends the partition.
 * @numElements: Amount of elements in the array.
**/
void quickSortLomutoRecursive(int *arr, ssize_t lowIndex, ssize_t highIndex, size_t numElements)
{
	ssize_t pivotPosition;

	if (lowIndex < highIndex)
	{
		pivotPosition = partitionLomuto(arr, lowIndex, highIndex, numElements);
		quickSortLomutoRecursive(arr, lowIndex, pivotPosition - 1, numElements);
		quickSortLomutoRecursive(arr, pivotPosition + 1, highIndex, numElements);
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

    quickSortLomutoRecursive(array, 0, size - 1, size);
}
