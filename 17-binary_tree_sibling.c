#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 *
 * @node: Pointer to the node for which to find the sibling.
 *
 * Return: Pointer to the sibling node, or NULL if no sibling found.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent) /* if node or node's parent is NULL */
		return (NULL);

	/* the way to find the sibling of a node is to check if */
	/* the node matches the left or right child of the parent */
	/* and return the non-matching child */

	if (node == node->parent->left)	  /* node matches parent's left child */
		return (node->parent->right); /* return the sibling */
	else /* node matches parent's right child */
		return (node->parent->left);  /* return the sibling */
}
