#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a binary tree node
 * @parent: A pointer to the parent of the new node.
 * @value: The integer value to be stored in the new node.
 *
 * Description: This function creates a new binary tree node with the given
 * parent and value, and initializes its left and right child pointers to NULL.
 *
 * Return: A pointer to the newly created node, or NULL if memory allocation
 * fails.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->parent = parent;
	new_node->n = value;
	new_node->left = new_node->right = NULL;
	return (new_node);
}

