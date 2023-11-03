#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Perform level-order traversal of a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node. The node's value is
 * passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *queue[1024];
	int front = 0, rear = 0;
	binary_tree_t *current;

	if (!tree || !func)
	return;

	current = (binary_tree_t *)tree;

	queue[rear] = current;
	rear++;

	while (front < rear)
	{
	current = queue[front];
	front++;

	func(current->n);

	if (current->left)
	{
		queue[rear] = current->left;
		rear++;
	}

	if (current->right)
	{
		queue[rear] = current->right;
		rear++;
	}
	}
}

