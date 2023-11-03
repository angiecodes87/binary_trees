#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor node of the two given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *node1 = first;
	const binary_tree_t *node2 = second;
	size_t depth1 = 0, depth2 = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	while (node1->parent)
	{
	node1 = node1->parent;
	depth1++;
	}

	while (node2->parent)
	{
	node2 = node2->parent;
	depth2++;
	}

	node1 = first;
	node2 = second;

	while (depth1 > depth2)
	{
	node1 = node1->parent;
	depth1--;
	}

	while (depth2 > depth1)
	{
	node2 = node2->parent;
	depth2--;
	}

	while (node1 && node2)
	{
	if (node1 == node2)
		return ((binary_tree_t *)node1);
		node1 = node1->parent;
		node2 = node2->parent;
	}

	return (NULL);
}

