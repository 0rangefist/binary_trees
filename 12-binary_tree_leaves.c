#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: Number of leaves in the binary tree,
 * or 0 if the tree is NULL.
 **/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* to get num of leaves in a binary tree, we traverse */
	/* through the tree and count each node we visit that */
	/* has no left and right children */

	size_t count = 0;

	if (!tree) /* if tree is NULL */
		return (0);

	/* using preorder traversal */
	if (!tree->left && !tree->right) /* no left and right children */
		count++; /* count the current node */

	/* add left child to the count */
	count = count + binary_tree_leaves(tree->left);

	/* add right child to the count */
	count = count + binary_tree_leaves(tree->right);

	return (count);
}
