#include "binary_trees.h"

/**
 * heapify_up - Moves the inserted node up to its correct position in the heap
 * @root: A pointer to the root node of the heap
 * @new_node: A pointer to the newly inserted node
 *
 * Return: A pointer to the created node, or NULL on failure
 */
void heapify_up(heap_t **root, heap_t *new_node)
{
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
	new_node->n = new_node->parent->n;
	new_node->parent->n = new_node->parent->n - new_node->n;
	new_node->n = new_node->parent->n + new_node->n;
	new_node = new_node->parent;
	}
	if (!new_node->parent)
	*root = new_node;
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: A double pointer to the root node of the heap
 * @value: The value to insert in the heap
 *
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
	return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

		parent = *root;
	while (parent->left && parent->right)
	{
	if (parent->left && parent->right)
		parent = parent->left;
	else if (parent->left)
		parent = parent->left;
	else
		parent = parent->right;
	}

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;
	heapify_up(root, new_node);

	return (new_node);
}

