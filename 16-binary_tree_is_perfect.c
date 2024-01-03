#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t get_depth(const binary_tree_t *tree);
const binary_tree_t *find_leaf(const binary_tree_t *tree);
int check_perfection(const binary_tree_t *tree,
		size_t leaf_depth, size_t current_level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Checks if a node is a leaf in a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf, returns 1, otherwise returns 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * get_depth - Returns the depth of a given node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of the node.
 */
size_t get_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + get_depth(tree->parent) : 0);
}

/**
 * find_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *find_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? find_leaf(tree->left) : find_leaf(tree->right));
}

/**
 * check_perfection - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @current_level: The current level of the tree.
 *
 * Return: If the tree is perfect, returns 1, otherwise returns 0.
 */
int check_perfection(const binary_tree_t *tree,
		size_t leaf_depth, size_t current_level)
{
	if (is_leaf(tree))
		return (current_level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (check_perfection(tree->left, leaf_depth, current_level + 1) &&
			check_perfection(tree->right, leaf_depth, current_level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, returns 0. Otherwise, returns 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (check_perfection(tree, get_depth(find_leaf(tree)), 0));
}
