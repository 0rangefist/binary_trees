#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The size (number of nodes) of the binary tree,
 * or 0 if the tree is NULL.
 **/
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* to get the size of a binary tree, we traverse */
	/* throught the tree and count each node we visit */

	size_t count = 0;

	if (!tree) /* if tree is NULL */
		return (0);

	/* using preorder traversal */
	/* count the current node */
	count++;

	/* add left child to the count */
	count = count + binary_tree_size(tree->left);

	/* add right child to the count */
	count = count + binary_tree_size(tree->right);

	return (count);
}
