#include "sort.h"

/**
 * swap - Funct that swaps two integers.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}