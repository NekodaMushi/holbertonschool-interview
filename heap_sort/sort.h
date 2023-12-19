#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/* Function Prototypes */

/**
 * print_array - Prints an array of integers.
 * @array: The array to be printed.
 * @size: Number of elements in @array.
 */
void print_array(const int *array, size_t size);

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
