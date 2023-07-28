#include "sort.h"

/**
 * swap_nodes - Swap two nodes of a doubly linked list
 * @list: The double linked list that contains the nodes
 * @node: The current node to be swapped with the next node
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->next->prev)
		node->prev->next = node->next;
	else
		*list = node->next;

	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;

	if (node->next)
		node->next->prev = node;
}

/**
 * get_last_node - Gets the last node of a doubly linked list
 * @h: Pointer to the double linked list
 *
 * Return: Pointer to the last node
 */
listint_t *get_last_node(listint_t *h)
{
	listint_t *current_node = h;

	while (current_node->next != NULL)
		current_node = current_node->next;

	return current_node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker sort algorithm.
 * @list: Double pointer to the doubly linked list to be sorted
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current_node = NULL, *start_node = NULL, *end_node = NULL;
	int sorting_direction = SORT_ASCENDING;

	if (!list || !(*list) || !(*list)->next)
		return;

	current_node = *list;
	start_node = current_node;
	end_node = get_last_node(*list);

	while (start_node != end_node)
	{
		if (current_node->n == current_node->next->n)
			break;
		else if (current_node->n > current_node->next->n && sorting_direction == SORT_ASCENDING)
		{
			swap_nodes(list, current_node);
			print_list(*list);
		}
		else if (current_node->next->n < current_node->n && sorting_direction == SORT_DESCENDING)
		{
			swap_nodes(list, current_node);
			current_node = current_node->prev;
			print_list(*list);
		}
		else if (sorting_direction == SORT_ASCENDING)
			current_node = current_node->next;
		else if (sorting_direction == SORT_DESCENDING)
			current_node = current_node->prev;

		if (sorting_direction == SORT_DESCENDING && current_node->next == start_node)
		{
			sorting_direction = SORT_ASCENDING;
			current_node = current_node->next;
		}

		if (sorting_direction == SORT_ASCENDING && current_node->prev == end_node)
		{
			end_node = end_node->prev;
			sorting_direction = SORT_DESCENDING;
			current_node = current_node->prev;
		}
	}
}
