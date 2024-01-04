#include "binary_trees.h"

bst_t *min_value(bst_t *root);
bst_t *delete_bst_node(bst_t *root, bst_t *node);
bst_t *remove_recursive_node(bst_t *root, bst_t *node, int value);
bst_t *remove_bst_value(bst_t *root, int value);

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
 * delete_bst_node - Deletes a node from a BST.
 * @root: Pointer to the root node of the BST.
 * @node: Pointer to the node to delete.
 *
 * Return: Pointer to the new root node after deletion.
 */
bst_t *delete_bst_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * remove_recursive_node - Removes a node from a BST recursively.
 * @root: Pointer to the root node of the BST.
 * @node: Pointer to the current node.
 * @value: Value to remove from the BST.
 *
 * Return: Pointer to the root node after deletion.
 */
bst_t *remove_recursive_node(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * remove_bst_value - Removes a node from a BST.
 * @root: Pointer to the root node of the BST.
 * @value: Value to remove from the BST.
 *
 * Return: Pointer to the new root node after deletion.
 */
bst_t *remove_bst_value(bst_t *root, int value)
{
	return (remove_recursive_node(root, root, value));
}
