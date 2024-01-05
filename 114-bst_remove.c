#include "binary_trees.h"

/**
 * min_value - Finds the minimum value in a BST.
 * @root: Pointer to the root node of the BST.
 *
 * Return: Pointer to the minimum value in the tree.
 */
bst_t *min_value(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the BST.
 * @value: Value to remove from the BST.
 *
 * Return: Pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}
		bst_t *temp = min_value(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

