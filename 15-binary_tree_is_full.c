#include "binary_trees.h"

/**
 * binary_tree_is_full - Counts the nodes with exactly 0 or
 * 2 children in a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Number of nodes with at 0 or 2 children,
 * or 0 if the tree is NULL.
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree) /* if tree is NULL */
		return (0);

	/* check if left or right child are present */
	if (tree->left != NULL || tree->right != NULL)
		return (binary_tree_is_full(tree->left)
				&& binary_tree_is_full(tree->right));
	else /* no children - so is full */
		return (1);
}
