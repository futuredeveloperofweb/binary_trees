#include "binary_trees.h"

/**
 * bst_insert -  inserts a value in a Binary Search Tree
 * @tree:  double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failurei
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *new;

	if (tree != NULL)
	{
		node = *tree;
		if (node == NULL)
		{
			new = binary_tree_node(node, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}
		if (value < node->n)
		{
			if (node->left != NULL)
				return (bst_insert(&node->left, value));
			new = binary_tree_node(node, value);
			if (new == NULL)
				return (NULL);
			return (node->left = new);
		}
		if (value > node->n)
		{
			if (node->right != NULL)
				return (bst_insert(&node->right, value));
			new = binary_tree_node(node, value);
			if (new == NULL)
				return (NULL);
			return (node->right = new);
		}
	}
	return (NULL);
}
