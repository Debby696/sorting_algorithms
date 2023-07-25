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
 * bubble_sort - this ssorts array of integers in ascending order.
 * @array: is array of integers to be sorted
 * @size: is tghe size of the array.
 *
 * Description: is to print the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, len = size;
	bool bubbled = false;

	if (array == NULL || size < 2)
		return;

	while (bubbled == false)
	{
		bubbled = true;
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(array + j, array + j + 1);
				print_array(array, size);
				bubbled = false;
			}
		}
		len--;
	}
}
