#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node.
 *         NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *heap, *new_node, *traverse;
	int tree_size, leaf_count, sub_tree, bit_count, level, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	heap = *root;
	tree_size = binary_tree_size(heap);
	leaf_count = tree_size;
	for (level = 0, sub_tree = 1; leaf_count >= sub_tree; sub_tree *= 2, level++)
		leaf_count -= sub_tree;

	for (bit_count = 1 << (level - 1); bit_count != 1; bit_count >>= 1)
		heap = leaf_count & bit_count ? heap->right : heap->left;

	new_node = binary_tree_node(heap, value);
	leaf_count & 1 ? (heap->right = new_node) : (heap->left = new_node);

	traverse = new_node;
	for (; traverse->parent && (traverse->n > traverse->parent->n);
			traverse = traverse->parent)
	{
		temp = traverse->n;
		traverse->n = traverse->parent->n;
		traverse->parent->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: The tree to measure the size of.
 *
 * Return: The size of the tree.
 *         0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
