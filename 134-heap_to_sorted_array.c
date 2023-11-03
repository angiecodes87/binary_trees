#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: A sorted array of integers, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	size_t arr_size = 0;

	if (!heap || !size)
		return (NULL);

	arr_size = binary_tree_size(heap);
	sorted_array = malloc(sizeof(int) * arr_size);
	if (!sorted_array)
		return (NULL);

	for (size_t i = 0; i < arr_size; i++)
	{
		sorted_array[i] = heap->n;
		heap_extract(&heap);
	}

	*size = arr_size;

	return (sorted_array);
}

