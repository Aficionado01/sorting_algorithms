#include "sort.h"

/**
 * counting_sort - Sorts an array using the counting sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 */
void counting_sort(int *array, size_t size)
{
  int *count_arr = NULL, *array_sorted = NULL, max_val = 0, i;

  if (array != NULL)
  {
    for (i = 0; i < (int)size; i++)
      max_val = (array[i] > max_val ? array[i] : max_val);
    max_val += 1;
    count_arr = malloc(sizeof(int) * (max_val));
    if (count_arr == NULL)
      return;
    array_sorted = malloc(sizeof(int) * size);
    if (array_sorted == NULL)
    {
      free(count_arr);
      return;
    }
    for (i = 0; i < (int)size; i++)
      count_arr[array[i]]++;
    for (i = 1; i < max_val; i++)
      count_arr[i] += count_arr[i - 1];
    print_array(count_arr, max_val);
    for (i = size - 1; i >= 0; i--)
    {
      count_arr[array[i]]--;
      array_sorted[count_arr[array[i]]] = array[i];
    }
    /* Replace the unsorted array with the sorted array */
    for (i = 0; i < (int)size; i++)
      array[i] = array_sorted[i];
    free(array_sorted);
    free(count_arr);
  }
}
