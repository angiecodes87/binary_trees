#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *node;
	queue_t *queue = NULL;
	int non_complete = 0;

	if (!tree)
		return (0);

	queue = queue_push(queue, (void *)tree);

	while (queue)
	{
	node = (binary_tree_t *)queue->data;
	queue = dequeue(queue);

	if (node->left)
	{
	if (non_complete)
		return (0);
	queue = queue_push(queue, (void *)node->left);
	}
	else
	{
	non_complete = 1;
	}

	if (node->right)
	{
	if (non_complete)
		return (0);
	queue = queue_push(queue, (void *)node->right);
	}
	else
	{
		non_complete = 1;
	}
	}

	return (1);
}

