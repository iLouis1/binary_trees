#include "binary_trees.h"

/**
 * array_to_bst - This builds a binary search tree from an array.
 * @array: Pointer to first element of the array to be converted.
 * @size: Number of elements in @array.
 *
 * Return: Pointer to root node of the created BST, or NULL upon failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t k, m;

	if (array == NULL)
		return (NULL);

	for (k = 0; k < size; k++)
	{
		for (m = 0; m < k; m++)
		{
			if (array[m] == array[k])
				break;
		}
		if (m == k)
		{
			if (bst_insert(&tree, array[k]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
