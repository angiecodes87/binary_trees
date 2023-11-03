#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *node1 = (binary_tree_t *)first;
	binary_tree_t *node2 = (binary_tree_t *)second;
	size_t depth1, depth2;

	if (!first || !second)
		return (NULL);

	depth1 = binary_tree_depth(node1);
	depth2 = binary_tree_depth(node2);

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

	while (node1 && node2 && node1 != node2)
	{
		node1 = node1->parent;
		node2 = node2->parent;
	}

	return (node1);
}

