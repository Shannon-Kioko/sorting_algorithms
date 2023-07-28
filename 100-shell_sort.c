#include "sort.h"

/**
 * shell_sort - function to sort an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t interval = 1, i, j;
    int temp;

    /* Calculate the initial interval using the Knuth sequence */
    while (interval < size / 3)
        interval = interval * 3 + 1;

    while (interval > 0)
    {
        /* Perform insertion sort with the current interval */
        for (i = interval; i < size; i++)
        {
            temp = array[i];
            j = i;

            /* Shift elements to their correct positions within the interval */
            while (j >= interval && array[j - interval] > temp)
            {
                array[j] = array[j - interval];
                j -= interval;
            }

            array[j] = temp;
        }

        /* Print the array after each interval decrease */
        for (i = 0; i < size; i++)
            printf("%d ", array[i]);
        printf("\n");

        /* Calculate the next interval using the Knuth sequence */
        interval = (interval - 1) / 3;
    }
}
