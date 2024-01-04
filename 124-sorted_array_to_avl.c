#include "binary_trees.h"

/**
 * create_avl - Recursively constructs an AVL tree
 *
 * @node: Pointer to the current node
 * @array: Input array of integers
 * @size: Size of the array
 * @dir: Direction flag (1 for left, 2 for right)
 * Return: No return
 */
void create_avl(avl_t **node, int *array, size_t size, int dir)
{
	size_t mid;

	if (size == 0)
		return;

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	if (dir == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mid]);
		create_avl(&((*node)->left), array, mid, 1);
		create_avl(&((*node)->left), array + mid + 1, (size - 1 - mid), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[mid]);
		create_avl(&((*node)->right), array, mid, 1);
		create_avl(&((*node)->right), array + mid + 1, (size - 1 - mid), 2);
	}
}

/**
 * sorted_array_to_avl - Creates the root node and invokes AVL tree creation
 *
 * @array: Input array of integers
 * @size: Size of the array
 * Return: Pointer to the root node
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t mid;

	root = NULL;

	if (size == 0)
		return (NULL);

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	root = binary_tree_node(root, array[mid]);

	create_avl(&root, array, mid, 1);
	create_avl(&root, array + mid + 1, (size - 1 - mid), 2);

	return (root);
}
