#include "binary_trees.h"
#include <limits.h>

/**
 * is_valid_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min_val: The value of the smallest node visited thus far.
 * @max_val: The value of the largest node visited thus far.
 *
 * Return: If the tree is a valid BST, returns 1; otherwise, returns 0.
 */
int is_valid_bst(const binary_tree_t *tree, int min_val, int max_val)
{
	if (tree != NULL)
	{
		if (tree->n < min_val || tree->n > max_val)
			return (0);
		return (is_valid_bst(tree->left, min_val, tree->n - 1) &&
				is_valid_bst(tree->right, tree->n + 1, max_val));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_valid_bst(tree, INT_MIN, INT_MAX));
}
