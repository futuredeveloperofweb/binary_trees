#include "binary_trees.h"

/**
 * totalNodes - calculates the total number of nodes in a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: Total number of nodes or 0 if tree is NULL
 */
size_t totalNodes(const binary_tree_t *tree)
{
	size_t countLeft = 0;
	size_t countRight = 0;

	if (!tree)
		return (0);

	if (tree->left)
		countLeft = 1 + totalNodes(tree->left);

	if (tree->right)
		countRight = 1 + totalNodes(tree->right);

	return (countLeft + countRight);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: pointer to the root node of the heap to convert
 * @size: address to store the size of the array
 *
 * Return: pointer to array sorted in descending order
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, *sortedArray = NULL;

	if (!heap || !size)
		return (NULL);

	*size = totalNodes(heap) + 1;

	sortedArray = malloc(sizeof(int) * (*size));

	if (!sortedArray)
		return (NULL);

	for (i = 0; heap; i++)
		sortedArray[i] = heap_extract(&heap);

	return (sortedArray);
}
