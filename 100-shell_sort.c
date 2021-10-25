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
 * shell_sort - Sorts an array using the shell sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void shell_sort(int *array, size_t size)
{
	int j;
	size_t i, gap = 0;

	if (array == NULL)
		return;
	gap = (size / 3) + 1;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = (int)(i - gap); j >= 0; j -= gap)
			{
				if (array[j] > array[j + gap])
				{
					swap_items(array, j, j + gap);
				}
			}
		}
		print_array(array, size);
	}
}
