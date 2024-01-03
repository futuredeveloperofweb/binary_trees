#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure or
 * if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_l_node = malloc(sizeof(binary_tree_t));

	if (new_l_node == NULL)
		return (NULL);
	if (parent == NULL)
		return (NULL);

	new_l_node->n = value;
	new_l_node->parent = parent;
	new_l_node->left = NULL;
	new_l_node->right = NULL;

	if (parent->left != NULL)
	{
		new_l_node->left = parent->left;
		new_l_node->left->parent = new_l_node;
	}
	parent->left = new_l_node;
	return (new_l_node);
}
