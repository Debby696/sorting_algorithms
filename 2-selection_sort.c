#include "sort.h"
/**
 * swap_int - this swaps two integers in an array.
 * @a: is the 1st integer to swap
 * @b: is the 2nd integer to swap
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - this sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: is the array of integers.
 * @size: is the size of the array.
 *
 * Description: it prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *small;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		small = array + j;
		for (k = j + 1; k < size; k++)
			small = (array[k] < *small) ? (array + k) : small;

		if ((array + j) != small)
		{
			swap_int(array + j, small);
			print_array(array, size);
		}
	}
}
