#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is root node in a binary tree.
 *
 * @node: Pointer to the node to be checked.
 *
 * Return: 1 if the node is a root node, 0 otherwise.
 **/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL) /* NULL node can't be a root node */
		return (0);

	/* a node is root if it has no parent */
	if (node->parent == NULL) /* check if it has no parent */
		return (1);

	return (0); /* if it has a parent, it isn't root node*/
}
