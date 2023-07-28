#ifndef SORT_H
#define SORT_H

#define SORT_ASCENDING 1
#define SORT_DESCENDING -1

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *xp, int *yp);
void bubble_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
listint_t *get_last_node(listint_t *h);
void swap_nodes(listint_t **list, listint_t *node);
void insertion_sort_list(listint_t **list);

 
/**
 * struct listint_t - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


#endif /* SORT_H */
