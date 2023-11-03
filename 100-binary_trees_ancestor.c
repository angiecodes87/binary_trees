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
	binary_tree_t *tmp_first = (binary_tree_t *)first;
	binary_tree_t *tmp_second = (binary_tree_t *)second;

	if (first == NULL || second == NULL)
	return (NULL);

	while (first != NULL)
	{
	tmp_second = (binary_tree_t *)second;
	while (tmp_second != NULL)
	{
	if (first == tmp_second)
	return ((binary_tree_t *)first);
	tmp_second = tmp_second->parent;
	}
	second = (binary_tree_t *)tmp_second;
	first = first->parent;
	}
	return (NULL);
}

