#include "sort.h"

/**
 * shell_sort - Sorts an array using the shell sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void shell_sort(int *array, size_t size)
{
	int tmp, i, gaps[2];
	const int gapSize = 2;
	size_t j, k, gap;

	gaps[0] = 1;
	for (i = 1; i < gapSize; i++)
		gaps[i] = gaps[i - 1] * 3 + 1; /* Knuth sequence */
	for (i = gapSize - 1; i >= 0; i--)
	{
		gap = gaps[i];
		for (j = gap; j < size; j++)
		{
			tmp = array[j];
			for (k = j; (k >= gap) && ((array[k - gap]) > tmp); k -= gap)
			{
				array[k] = array[k - gap];
			}
			array[k] = tmp;
		}
		print_array(array, size);
	}
}
