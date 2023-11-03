#include "binary_trees.h"

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: A pointer to the root node.
 *
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
	return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if it's a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, diff;

	if (!tree)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	diff = left_height - right_height;

	if (diff > 1 || diff < -1)
		return (0);

	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}

