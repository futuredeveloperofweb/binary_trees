#include "binary_trees.h"

levelorder_queue_t *create_queue_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void dequeue(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_queue_node - Creates a new node for the level order traversal queue.
 * @node: The binary tree node for the new queue node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new queue node.
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
 * free_queue - Frees a level order traversal queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * enqueue - Adds a node to the end of a level order traversal queue.
 * @node: The binary tree node to add to the queue.
 * @head: A pointer to the head of the queue.
 * @tail: A pointer to the tail of the queue.
 *
 * Description: Exits with a status code of 1 on malloc failure.
 */
void enqueue(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new_node;

	new_node = create_queue_node(node);

	if (new_node == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * dequeue - Removes the head of a level order traversal queue.
 * @head: A pointer to the head of the queue.
 */
void dequeue(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Exits with a status code of 1 on malloc failure.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_queue_node((binary_tree_t *)tree);

	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			enqueue(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			enqueue(head->node->right, head, &tail);
		}
		else
			flag = 1;
		dequeue(&head);
	}
	return (1);
}
