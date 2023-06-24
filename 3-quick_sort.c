#include "sort.h"

/**
 * swap2 - Funct that swaps two integers.
 * @array: the array to swap
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap2(int *array, int a, int b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
 * lomuto_partition - funct to partition an arr using Lomuto scheme
 *
 * @array: array of integers
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 *
 * Return: the index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap2(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap2(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - helper function to implement quick sort algorithm
 *
 * @array: array of integers
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - funct to sort an array of ints using quick sort algorithm
 *
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
