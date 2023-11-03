#include "binary_trees.h"

/**
 * swap_nodes - Swaps two nodes in a heap
 * @heap: Pointer to the heap
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(heap_t **heap, heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;

	*heap = node1;
}

/**
 * heapify_down - Restores the max-heap property after node removal
 * @heap: Pointer to the heap
 */
void heapify_down(heap_t **heap)
{
	heap_t *curr = *heap;
	heap_t *max = NULL;
	int swapped = 1;

	while (swapped)
	{
	swapped = 0;
	if (curr->left && curr->left->n > curr->n)
	max = curr->left;
	else
	max = curr;

	if (curr->right && curr->right->n > max->n)
	max = curr->right;

	if (max != curr)
	{
	swap_nodes(heap, curr, max);
	swapped = 1;
	}
	}
}

/**
 * get_tree_height - Computes the height of a binary tree
 * @root: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
size_t get_tree_height(const binary_tree_t *root)
{
	size_t left_height, right_height;

	if (!root)
	return (0);

	left_height = get_tree_height(root->left);
	right_height = get_tree_height(root->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * extract_last_node - Removes and returns the last node in the heap
 * @heap: Pointer to the heap
 *
 * Return: The last node in the heap
 */
heap_t *extract_last_node(heap_t **heap)
{
	size_t height, mask;
	heap_t *curr = *heap;

	if (!curr)
	return (NULL);

	height = get_tree_height(curr);
	mask = 1 << (height - 1);

	while (mask > 0)
	{
	if (mask & 1)
	{
	if (curr->right)
		curr = curr->right;
	else
		curr = curr->left;
	}
	else
	{
	if (curr->left)
		curr = curr->left;
	else
		curr = curr->right;
	}
		mask >>= 1;
	}

	if (curr->parent->left == curr)
		curr->parent->left = NULL;
	else
		curr->parent->right = NULL;

	return (curr);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: The value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int root_value;
	heap_t *last_node;

	if (!root || !*root)
	return (0);

	root_value = (*root)->n;

	last_node = extract_last_node(root);

	if (last_node == *root)
	{
	free(last_node);
	*root = NULL;
	return (root_value);
	}

	(*root)->n = last_node->n;
	if (last_node->parent->left == last_node)
	last_node->parent->left = NULL;
	else
	last_node->parent->right = NULL;
	free(last_node);

	heapify_down(root);

	return (root_value);
}

