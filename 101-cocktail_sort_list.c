#include "sort.h"

void node_swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void node_swap_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * node_swap_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void node_swap_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tempo = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tempo;
	else
		*list = tempo;
	tempo->prev = (*shaker)->prev;
	(*shaker)->next = tempo->next;
	if (tempo->next != NULL)
		tempo->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tempo;
	tempo->next = *shaker;
	*shaker = tempo;
}

/**
 * node_swap_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void node_swap_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tempo = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tempo;
	else
		*tail = tempo;
	tempo->next = (*shaker)->next;
	(*shaker)->prev = tempo->prev;
	if (tempo->prev != NULL)
		tempo->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tempo;
	tempo->prev = *shaker;
	*shaker = tempo;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				node_swap_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				node_swap_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
