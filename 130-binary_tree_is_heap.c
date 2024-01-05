#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"


/**
 * max_check - checks if all nodes have the maximum value
 * @tree: pointer to the root node
 * Return: 1 if all nodes have the maximum value, 0 otherwise
 **/
int max_check(const binary_tree_t *tree)
{
	int left_result = 1, right_result = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		left_result = max_check(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		right_result = max_check(tree->right);
	}
	return (left_result && right_result);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a max heap
 * @tree: pointer to the root node
 * Return: 1 if the tree is a max heap, 0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int is_complete;

	if (!tree)
		return (0);

	is_complete = binary_tree_is_complete(tree);
	if (!is_complete)
		return (0);
	return (max_check(tree));
}
