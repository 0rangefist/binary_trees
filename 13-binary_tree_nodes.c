#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1
 * child in a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Number of nodes with at least 1 child,
 * or 0 if the tree is NULL.
 **/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* to get num of nodes in a binary tree with at least */
	/* 1 child, we traverse through the tree and count each */
	/* node we visit that has either a left or right child */

	size_t count = 0;

	if (!tree) /* if tree is NULL */
		return (0);

	/* using preorder traversal */
	if (tree->left || tree->right) /* either left or right child */
		count++;					 /* count the current node */

	/* add left child to the count */
	count = count + binary_tree_nodes(tree->left);

	/* add right child to the count */
	count = count + binary_tree_nodes(tree->right);

	return (count);
}
