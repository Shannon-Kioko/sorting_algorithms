#ifndef SORT_H
#define SORT_H

#define SORT_ASCENDING 1
#define SORT_DESCENDING -1

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
};

typedef struct listint_s listint_t;
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *xp, int *yp);
void nodes_swapper(listint_t **h, listint_t **n1, listint_t *n2);
void bubble_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
listint_t *get_last_node(listint_t *h);
void swap_nodes(listint_t **list, listint_t *node);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t low, size_t high, size_t size);
void recursive_lomuto_quicksort(int *array, ssize_t low, ssize_t high, size_t size);
void quick_sort(int *array, size_t size);
listint_t *create_listint(const int *array, size_t size);
int hoare_partition(int *array, size_t low, size_t high, size_t size);
void hoare_quicksort_recursive(int *array, size_t low, size_t high, size_t size);
void quick_sort_hoare(int *array, size_t size);
int get_max(int *array, int size);
void counting_sort_radix(int *array, size_t size, int exp);
void radix_sort(int *array, size_t size);


#endif /* SORT_H */
