#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root = tree->left, *tp = new_root->right;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	new_root->right = tree;
	tree->left = tp;
	if (tp != NULL)
		tp->parent = tree;
	tp = tree->parent;
	tree->parent = new_root;
	new_root->parent = tp;
	if (tp != NULL)
	{
		if (tp->left == tree)
			tp->left = new_root;
		else
			tp->right = new_root;
	}
	return (new_root);
}
