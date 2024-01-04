#include "binary_trees.h"
#include "limits.h"

size_t tree_height(const binary_tree_t *node);
int is_avl_helper(const binary_tree_t *node, int min_val, int max_val);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * tree_height - Finds the height of a binary tree.
 * @node: A pointer to the root node of the tree.
 *
 * Return: Height of the tree. If node is NULL, returns 0.
 */
size_t tree_height(const binary_tree_t *node)
{
	if (node)
	{
		size_t left_height = node->left ? 1 + tree_height(node->left) : 1;
		size_t right_height = node->right ? 1 + tree_height(node->right) : 1;

		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * is_avl_helper - Checks if a tree is a valid AVL tree.
 * @node: A pointer to the root node of the tree.
 * @min_val: The minimum value allowed in the tree.
 * @max_val: The maximum value allowed in the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int is_avl_helper(const binary_tree_t *node, int min_val, int max_val)
{
	size_t left_height, right_height, diff;

	if (node)
	{
		if (node->n < min_val || node->n > max_val)
			return (0);
		left_height = tree_height(node->left);
		right_height = tree_height(node->right);
		diff = (left_height > right_height) ?
			left_height - right_height : right_height - left_height;
		if (diff > 1)
			return (0);
		return (is_avl_helper(node->left, min_val, node->n - 1) &&
				is_avl_helper(node->right, node->n + 1, max_val));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
