#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value to be inserted
 *
 * Return: A pointer to the newly created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
	return (NULL);

	if (!*tree)
	{
	*tree = binary_tree_node(NULL, value);
	if (!*tree)
	return (NULL);
	return (*tree);
	}

	if (value < (*tree)->n)
	{
	(*tree)->left = avl_insert(&((*tree)->left), value);
	if (!(*tree)->left)
	return (NULL);
	}
	else if (value > (*tree)->n)
	{
	(*tree)->right = avl_insert(&((*tree)->right), value);
	if (!(*tree)->right)
		return (NULL);
	}
	else
		return (NULL);

	(*tree)->height = 1 + MAX(binary_tree_height((*tree)->left),
	binary_tree_height((*tree)->right));

	return (avl_balance(tree));
}

