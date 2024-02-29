#include "binary_trees.h"

/**
 * array_to_heap - This builds a Max Binary Heap tree from an array
 * @array: Pointer to first element of the array to be converted
 * @size: Number of element in the array
 *
 * Return: a pointer to the root node of the created Binary Heap
 * NULL on failure
 */

heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int k;
	heap_t *root = NULL;

	for (k = 0; k < size; k++)
		heap_insert(&root, array[k]);

	return (root);
}
