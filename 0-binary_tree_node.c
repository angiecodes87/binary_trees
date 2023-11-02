#include "binary_trees.h"
#include <stdlib.h>

/**
 * Create a binary tree node.
 * @param parent: The parent of the new node.
 * @param value: The value to be stored in the new node.
 *
 * @return: A pointer to the newly created node.
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

