#include "sort.h"

/**
 * swap_int - this swap two integers in an array.
 * @a: is the first integer to swap.
 * @b: is the second integer to swap.
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - this sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: is the array of integers.
 * @size: is the size of the array.
 *
 * Description: this uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, j, k;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			k = j;
			while (k >= gap && array[k - gap] > array[k])
			{
				swap_int(array + k, array + (k - gap));
				k -= gap;
			}
		}
		print_array(array, size);
	}
}
