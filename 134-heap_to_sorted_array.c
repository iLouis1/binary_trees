#include "binary_trees.h"

/**
 * tree_size - This measures sum of heights of a binary tree
 * @tree: Pointer to root node of the tree to measure the height
 *
 * Return: If tree is NULL, return Height or 0
 */

size_t tree_size(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_size(tree->left);

	if (tree->right)
		height_r = 1 + tree_size(tree->right);

	return (height_l + height_r);
}

/**
 * heap_to_sorted_array - This converts a Binary Max Heap
 * to sorted array of integers
 * @heap: Pointer to root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Generated array, NULL on failure
 *
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int k, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (k = 0; heap; k++)
		a[k] = heap_extract(&heap);

	return (a);
}
