#include "sort.h"

/**
 * radix_sort - Sorts an array using the radix sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void radix_sort(int *array, size_t size)
{
	int digits = 0, i, j, max_val = 0, base = 10, pow_b;
	int *bins = NULL, *counts = NULL;

	if (array == NULL)
		return;
	for (i = 0; i < (int)size; i++)
		max_val = array[i] > max_val ? array[i] : max_val;
	while (max_val)
		digits++, max_val /= 10;
	bins = malloc(sizeof(int) * size);
	if (bins == NULL)
		return;
	counts = malloc(sizeof(int) * base);
	if (counts == NULL)
	{
		free(bins);
		return;
	}
	for (i = 0, pow_b = 1; i < digits; i++, pow_b *= base)
	{
		for (j = 0; j < base; j++)
			counts[j] = 0;
		for (j = 0; j < (int)size; j++)
			counts[(array[j] / pow_b) % base]++;
		for (j = 1; j < base; j++)
			counts[j] += counts[j - 1];
		for (j = (int)size - 1; j >= 0; j--)
			bins[--counts[(array[j] / pow_b) % base]] = array[j];
		for (j = 0; j < (int)size; j++)
			array[j] = bins[j];
		print_array(array, size);
	}
	free(bins);
	free(counts);
}
