#include "sort.h"

void counting_sort(int *array, size_t size)
{
    int *output_array = (int *)malloc(size * sizeof(int));

    if (array == NULL || size < 2)
        return;

    int max_value = array[0];
    size_t i;

    /* Find the maximum value in the array to determine the counting array size */
    for (i = 1; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Create the counting array of size max_value + 1 and initialize with zeros */
    int *counting_array = (int *)calloc(max_value + 1, sizeof(int));
    if (counting_array == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    /* Populate the counting array by counting occurrences of each element */
    for (i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    printf("Counting array: ");
    for (i = 0; i <= max_value; i++)
        printf("%d, ", counting_array[i]);
    printf("\n");

    /* Modify the counting array to store the correct positions of each element */
    
    for (i = 1; (int)i <= max_value; i++)
        counting_array[i] += counting_array[i - 1];

    /* Create a temporary output array to store the sorted elements */
    if (output_array == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        free(counting_array);
        return;
    }

    /* Populate the output array using the counting array */
    for (i = size - 1; i < size; i--)
    {
        output_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy the sorted output back to the original array */
    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    /* Free the allocated memory */
    free(output_array);
    free(counting_array);
}
