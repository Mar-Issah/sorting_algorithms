#include "sort.h"

/**

* get_max - Func that get the max value.
* @array: An array of integers.
* @size: The size of the array.
Return: The maximum integer in the array.
*/
int get_max(int *array, int size)
{
	if (array == NULL || size < 1)
		return 0;

	int max = array[0];
	for (int i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return max;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int idx;
	int max = get_max(array, size);
	int *count = calloc(max + 1, sizeof(int));
	int *sorted = malloc(sizeof(int) * size);

	if (array == NULL || size < 2)
		return;

	if (count == NULL || sorted == NULL)
	{
		free(count);
		free(sorted);
		return;
	}

	for (idx = 0; idx < (int)size; idx++)
		count[array[idx]]++;

	for (idx = 1; idx <= max; idx++)
		count[idx] += count[idx - 1];

	for (idx = size - 1; idx >= 0; idx--)
	{
		sorted[count[array[idx]] - 1] = array[idx];
		count[array[idx]]--;
	}

	for (int i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(count);
	free(sorted);
}