#include "sort.h"

void swap_int(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
 * lomuto_partition - this order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: is the array of integers.
 * @size: is the size of the array.
 * @left: is the starting index of the subset to order.
 * @right: is the ending index of the subset to order.
 *
 * Return: final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_int(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_int(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort -this implement the quicksort algorithm through recursion.
 * @array: is array of integers to sort.
 * @size: is the size of the array.
 * @left: is the starting index of the array partition to order.
 * @right: is the ending index of the array partition to order.
 *
 * Description: it uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - this function sorts an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: is an array of integers.
 * @size: is the size of the array.
 *
 * Description: it uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
