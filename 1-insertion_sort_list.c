#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the insertion sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	/* Initialize a new list to hold the sorted nodes */
	listint_t *current, **ptr_sorted, *sorted = NULL;

	if (*list == NULL || (*list)->next == NULL)
		return;

	while (*list != NULL)
	{
		current = *list;
		ptr_sorted = &sorted;

		*list = (*list)->next; /* Move to the next node in the original list */

		/* Find the correct position in the sorted list to insert the current node */
		while (*ptr_sorted != NULL && (*ptr_sorted)->n < current->n)
		{
			ptr_sorted = &(*ptr_sorted)->next;
		}

		/* Insert the current node into the sorted list */
		current->next = *ptr_sorted;
		if (*ptr_sorted != NULL)
		{
			(*ptr_sorted)->prev = current;
		}
		current->prev = *ptr_sorted;
		*ptr_sorted = current;
	}

	*list = sorted; /* original list points to the sorted list */
}
