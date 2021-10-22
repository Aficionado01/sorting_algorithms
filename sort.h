#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef SWAP
#define SWAP(array, a, b) {\
	tmp = array[a]; \
	array[a] = array[b]; \
	array[b] = tmp; \
}
#endif

/**
 * struct listint_s - Represents a doubly linked list node.
 * @n: Integer stored in the node.
 * @prev: Pointer to the previous element of the list.
 * @next: Pointer to the next element of the list.
 */
typedef struct listint_s
{
	/* Integer stored in the node. */
	const int n;
	/* Pointer to the previous element of the list. */
	struct listint_s *prev;
	/* Pointer to the next element of the list. */
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_items(int *array, size_t l, size_t r);
void bubble_sort(int *array, size_t size);
void swap_nodes(listint_t *left, listint_t *right);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void top_down_merge(int *array, int *array_c, size_t l, size_t m, size_t r);
void split_merge(int *array, int *array_c, size_t l, size_t r);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
