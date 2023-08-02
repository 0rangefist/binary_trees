#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf in a binary tree.
 *
 * @node: Pointer to the node to be checked.
 *
 * Return: 1 if the node is a leaf, 0 otherwise.
 **/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node ==  NULL) /* NULL node can't be a leaf */
		return (0);

	/* a node is a leaf if it has no children */
	if (!node->left && !node->right) /* no left & right children */
		return (1);
	return (0);
}
