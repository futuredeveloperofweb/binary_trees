#include "binary_trees.h"

/**
 * binary_tree_is_full -  checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 0 If tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;
	if (tree == NULL)
		return (0);
	int has_both_children = (tree->left != NULL && tree->right != NULL);
	int has_no_children = (tree->left == NULL && tree->right == NULL);
	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);
	return ((has_both_children || has_no_children) && left_full && right_full);
}
