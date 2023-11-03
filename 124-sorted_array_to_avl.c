#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new_node;

	if (size == 0)
	return (NULL);

	size_t middle = size / 2;

	new_node = binary_tree_node(NULL, array[middle]);
	if (new_node == NULL)
		return (NULL);
	new_node->left = sorted_array_to_avl(array, middle);
	new_node->right = sorted_array_to_avl(array + middle + 1,
			size - middle - 1);

	return (new_node);
}

