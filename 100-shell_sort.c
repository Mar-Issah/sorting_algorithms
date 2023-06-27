#include "sort.h"

void swap(int *a, int *b);
/**
 * shell_sort - Sort an arr of integers using shell sort algo.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{

	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = size / 2; interval > 0; interval /= 2)
	{
		for (i = interval; i < size; i++)
		{
			int temp = array[i];

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}

			array[j] = temp;
		}
		print_array(array, size);
	}
}
