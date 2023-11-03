#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes with at least one child in a
 * binary tree.
 * @tree: A pointer to the root node of the tree to count the nodes.
 *
 * Return: The number of nodes with at least one child in the binary tree.
 * If the tree is NULL, return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	size_t left_nodes = binary_tree_nodes(tree->left);
	size_t right_nodes = binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		return (1 + left_nodes + right_nodes);
	else
		return (left_nodes + right_nodes);
}

