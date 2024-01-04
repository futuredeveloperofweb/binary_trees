#include "binary_trees.h"

/**
 * heap_from_array - creates a Max Binary Heap from an array
 * @arr: pointer to the first element of the input array
 * @sz: number of elements in the array
 *
 * Return: pointer to the root of the Max Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
