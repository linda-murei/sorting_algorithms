#include "sort.h"

void quick_sort_recurse(int *array, size_t size, int *o_array, size_t o_size);

/**
 * quick_sort - Sorting Algorithm
 * @array: The array to be sorted.
 * @size: The size of the array to be sorted.
 *
 * A quick-sort algorithm for sorting an array of integers.
 *
 * Return: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_recurse(array, size, array, size);
}

/**
 * quick_sort_recurse - Sorting Algorithm
 * @array: The subarray to be sorted in the recursive call.
 * @size: The size of the subarray to be sorted in the recursive call.
 * @o_array: Pointer to the start of original array.
 * @o_size: Size of original array.
 *
 * A quick-sort algorithm for sorting an array of integers using recursion.
 *
 * Return: Nothing.
 */

void quick_sort_recurse(int *array, size_t size, int *o_array, size_t o_size)
{
	size_t cursor_idx, pivot_idx, swap_idx;
	int hold, left_size, right_size;

	/* Check for base cases: empty array or array with a single element */
	if (array == NULL || size < 2)
		return;

	/* Set the pivot index as the last element of the array */
	pivot_idx = size - 1;
	cursor_idx = 0;
	swap_idx = -1;

	while (cursor_idx <= pivot_idx)
	{
		/* Compare the current element with the pivot element */
		if (array[cursor_idx] <= array[pivot_idx])
		{
			swap_idx++;
			if (cursor_idx > swap_idx)
			{
				hold = array[cursor_idx];
				array[cursor_idx] = array[swap_idx];
				array[swap_idx] = hold;
				print_array(o_array, o_size);
			}
		}
		cursor_idx++;
	}

	/* Determine the sizes of the left and right subarrays */
	left_size = swap_idx;
	right_size = size - swap_idx - 1;

	/* Recursively sort the left and right subarrays */
	quick_sort_recurse(array, left_size, o_array, o_size);
	quick_sort_recurse(array + swap_idx + 1, right_size, o_array, o_size);
}
