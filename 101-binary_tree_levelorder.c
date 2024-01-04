#include "binary_trees.h"

/**
 * create_queue_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new queue node to contain.
 *
 * Return: If an error occurs, NULL. Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_queue_node(binary_tree_t *node)
{
	levelorder_queue_t *new_node;

	new_node = malloc(sizeof(levelorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * push_node - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to process and push.
 * @head: A pointer to the head of the queue.
 * @tail: A pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push_node(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new_node;

	func(node->n);

	if (node->left != NULL)
	{
		new_node = create_queue_node(node->left);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
	if (node->right != NULL)
	{
		new_node = create_queue_node(node->right);
		if (new_node == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

/**
 * dequeue - Dequeues the head of a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void dequeue(levelorder_queue_t **head)
{
	levelorder_queue_t *temp_node;

	temp_node = (*head)->next;
	free(*head);
	*head = temp_node;
}

/**
 * binary_tree_levelorder - Performs a level-order traversal of a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_queue_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		push_node(head->node, head, &tail, func);
		dequeue(&head);
	}
}
