#include "binary_trees.h"

/**
 * binary_tree_sibling - a function that finds the sibling of a node
 * @node:  is a pointer to the node to find the sibling
 * Return: NULL if node is NULL or the parent is NULL or has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = node->parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (parent->left == node && parent->right != NULL)
		return (parent->right);
	else if (parent->right == node && parent->right != NULL)
		return (parent->left);
	else
		return (NULL);
}
