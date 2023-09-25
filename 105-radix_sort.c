#include "sort.h"

/**
 * radix_sort - sorting an array using radix_sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 *
 **/
void radix_sort(int *array, size_t size)
{
	size_t i;
	int yum;

	if (array == NULL || size == 1)
		return;

	yum = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > yum)
			yum = array[i];
	}

	for (i = 1; yum / i > 0; i = i * 10)
	{
		csort(array, size, i);
		print_array(array, size);
	}
}

/**
 * csort - counting sort function
 * @array: array to be sorted
 * @size: size of the array
 * @div: div power of 10
 * Return: Void
 *
 **/
void csort(int *array, size_t size, int div)
{
	size_t i, digit, prevcount;
	int *new, n, count[10], yum;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	new = malloc(sizeof(int) * size);

	if (new == NULL)
		return;

	for (i = 0; i < size; i++)
		new[i] = array[i];

	for (i = 0; i < size; i++)
	{
		digit = (array[i] / div) % 10;
		count[digit]++;
	}
	for (i = 1; i < 10; i++)
	{
		prevcount = count[i - 1];
		count[i] += prevcount;
	}

	for (n = size - 1; n >= 0; n--)
	{
		yum = (new[n] / div) % 10;
		array[count[yum] - 1] = new[n];
		count[yum]--;
	}
	free(new);
}
