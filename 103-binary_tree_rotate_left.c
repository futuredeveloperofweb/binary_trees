#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after the rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *left_sub;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	left_sub = new_root->left;
	new_root->left = tree;
	tree->right = left_sub;
	if (left_sub != NULL)
		left_sub->parent = tree;
	left_sub = tree->parent;
	tree->parent = new_root;
	new_root->parent = left_sub;
	if (left_sub != NULL)
	{
		if (left_sub->left == tree)
			left_sub->left = new_root;
		else
			left_sub->right = new_root;
	}

	return (new_root);
}
