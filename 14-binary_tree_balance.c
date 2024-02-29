#include "binary_trees.h"

/**
 * binary_tree_balance - This measures balance factor of a binary tree.
 * @tree: Pointer to root node of the tree to measure the balance factor.
 *
 * Return: Return 0, if tree is NULL, else return balance factor.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - This measures height of a binary tree.
 * @tree: Pointer to root node of the tree to measure the height.
 *
 * Return: Your function must return 0, if tree is NULL, else return height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
