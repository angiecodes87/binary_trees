#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: Pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, 0 otherwise. If the node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
	return (1);
	return (0);
}

/**
 * binary_tree_nodes - Counts the nodes with at least one child in a binarytree
 * @tree: Pointer to the root node of the tree to count nodes in.
 *
 * Description: A NULL pointer is not considered a node.
 *
 * Return: The number of nodes with at least one child in the binary tree.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_count, right_count;

	if (tree == NULL)
	return (0);

	left_count = binary_tree_nodes(tree->left);
	right_count = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
	return (1 + left_count + right_count);

	return (left_count + right_count);
}

