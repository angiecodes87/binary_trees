#include "binary_trees.h"

/**
 * binary_tree_is_complete - Check if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *queue[1024];
	int front = 0, rear = 0;
	int null_flag = 0;

	if (!tree)
	return (0);

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{

	const binary_tree_t *current = queue[front];

	front++;

	if (!current)
	{
	null_flag = 1;
	continue;
	}

	if (null_flag && current)
		return (0);

	queue[rear] = current->left;
	rear++;
	queue[rear] = current->right;
	rear++;

	return (1);
}

