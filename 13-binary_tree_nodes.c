#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: 0 If tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_n, right_n, node_with_child;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		node_with_child = 1;
	else
		node_with_child = 0;

	left_n = binary_tree_nodes(tree->left);
	right_n = binary_tree_nodes(tree->right);
	return (left_n + right_n + node_with_child);
}

