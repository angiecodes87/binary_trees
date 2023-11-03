#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth = 0;
	size_t leaves = 0;
	size_t target_leaves;

	if (tree == NULL)
		return (0);

	target_leaves = 1;
	while (tree->left)
	{
		depth++;
		target_leaves *= 2;
		tree = tree->left;
	}

	leaves = 1;
	while (tree->right)
	{
		leaves++;
		tree = tree->right;
	}

	if (depth == leaves && leaves == target_leaves)
		return (1);

	return (0);
}

