#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * recursive_search - Helper function to perform recursive advanced binary search
 * @array: Pointer to the first element of the array to search in
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 * @value: Value to search for
 * Return: First index where value is located, or -1
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (right < left)
		return (-1);

	print_array(array + left, right - left + 1);

	mid = left + (right - left) / 2;
	if (array[mid] == value)
{
    if (mid == left || array[mid - 1] != value)
        return (mid);
    else
        return recursive_search(array, left, mid - 1, value);
}

	if (array[mid] < value)
		return recursive_search(array, mid + 1, right, value);
	return recursive_search(array, left, mid - 1, value);
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: First index where value is located, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return recursive_search(array, 0, size - 1, value);
}
