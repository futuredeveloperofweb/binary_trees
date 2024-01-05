#include "binary_trees.h"

/**
 * array_to_bst - Converts an array into a binary search tree (BST).
 * @arr: Pointer to the first element of the array to be converted.
 * @len: Number of elements in @arr.
 *
 * Returns: A pointer to the root node of the created BST, NULL on failure.
 */
bst_t *array_to_bst(int *arr, size_t len)
{
	bst_t *bst_root = NULL;
	size_t i, j;

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[j] == arr[i])
				break;
		}
		if (j == i)
		{
			if (bst_insert(&bst_root, arr[i]) == NULL)
				return (NULL);
		}
	}

	return (bst_root);
}
