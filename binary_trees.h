#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/* Define the levelorder_queue_t struct */
typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
void dequeue(levelorder_queue_t **head);
void push_node(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void free_queue(levelorder_queue_t *head);
levelorder_queue_t *create_queue_node(binary_tree_t *node);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
int is_valid_bst(const binary_tree_t *tree, int min_val, int max_val);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *array_to_avl(int *array, size_t size);
avl_t *sorted_array_to_avl(int *array, size_t size);
void create_tree(avl_t **node, int *array, size_t size, int mode);
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *array_to_heap(int *array, size_t size);
int *heap_to_sorted_array(heap_t *heap, size_t *size);


#endif
