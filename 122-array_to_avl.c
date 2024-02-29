#include "binary_trees.h"

/**
 * array_to_avl - This builds an AVL tree from an array.
 * @array: Pointer to first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: Pointer to root node of the created AVL, or NULL upon failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
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
			if (avl_insert(&tree, array[k]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
