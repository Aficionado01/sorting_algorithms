#include "sort.h"

/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @l: The index of the left item.
 * @r: The index of the right item.
 */
void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * quick_sort_range_hoare - Sorts a sub array using the
 * quick sort algorithm and Hoare's partition scheme.
 * @array: The array containing the sub-array.
 * @low: The starting position of the sub-array.
 * @high: The ending position of the sub-array.
 * @size: The length of the array.
 */
void quick_sort_range_hoare(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	/* Hoare's partition */
	i = low;
	j = high;
	while (TRUE)
	{
		while (array[i] < pivot)
			i++;
		while ((array[j] > pivot) && (j > 0))
			j--;
		if (i >= j)
			break;
		swap_items(array, i, j);
		print_array(array, size);
	}
	if (j - low > 0)
		quick_sort_range_hoare(array, low, j > 0 ? j - 1 : 0, size);
	if (high - j > 1)
		quick_sort_range_hoare(array, j + 1, j == high ? high - 1 : high, size);
}

/**
 * quick_sort_hoare - Sorts an array using the quick sort algorithm
 * and Hoare's partition scheme.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if ((array != NULL) && (size > 1))
	{
		quick_sort_range_hoare(array, 0, size - 1, size);
	}
}
