#include "sort.h"

/**
 * nodes_swapper - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void nodes_swapper(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
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
	listint_t *iteran, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iteran = (*list)->next; iteran != NULL; iteran = tmp)
	{
		tmp = iteran->next;
		insert = iteran->prev;
		while (insert != NULL && iteran->n < insert->n)
		{
			nodes_swapper(list, &insert, iteran);
			print_list((const listint_t *)*list);
		}
	}
}
