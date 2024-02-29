#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - This returns minimum value of binary search tree.
 * @root: Pointer to root node of the BST to search.
 *
 * Return: Minimum value in @tree.
 */

bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - This deletes a node from a binary search tree.
 * @root: Pointer to root node of the BST.
 * @node: Pointer to node to delete from the BST.
 *
 * Return: Pointer to new root node after deletion.
 */

bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;

		else if (parent != NULL)
			parent->right = node->left;

		if (node->left != NULL)
			node->left->parent = parent;

		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* The two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - This removes a node from a binary search tree recursively.
 * @root: Pointer to root node of the BST to remove a node from.
 * @node: Pointer to current node in the BST.
 * @value: Value to remove from the BST.
 *
 * Return: Pointer to root node after deletion.
 */

bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));

		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - This removes a node from a binary search tree.
 * @root: Pointer to root node of the BST to remove a node from.
 * @value: Value to remove in the BST.
 *
 * Return: Pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 * is replaced with its first in-order successor.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
