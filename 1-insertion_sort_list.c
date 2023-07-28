#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using insertion sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the linked list.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	if (*list == NULL || (*list)->next == NULL)
		return; /* Guard clause if the list is empty or only has one element */
	
	/* Initializing a new list to hold the sorted nodes */
	listint_t *sorted = NULL;

	while (*list != NULL)
	{
		listint_t *current = *list;
		listint_t **sorted_ptr = &sorted;

		*list = (*list)->next; /* Move to the next node in the original list */

		/* Find the correct position in the sorted list to insert the current node */
		while (*sorted_ptr != NULL && (*sorted_ptr)->n < current->n)
		{
			sorted_ptr = &(*sorted_ptr)->next;
		}

		/* Insert the current node into the sorted list */
		current->next = *sorted_ptr;
		if (*sorted_ptr != NULL)
		{
			(*sorted_ptr)->prev = current;
		}
		current->prev = *sorted_ptr;
		*sorted_ptr = current;
	}
	
	*list = sorted; /* Update the original list to point to the sorted list */
}
