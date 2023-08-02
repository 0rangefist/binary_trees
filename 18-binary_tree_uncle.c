#include "binary_trees.h"
#include "17-binary_tree_sibling.c"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 *
 * @node: Pointer to the node for which to find the sibling.
 *
 * Return: Pointer to the uncle node, or NULL if no uncle found.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent) /* if node or node's parent is NULL */
		return (NULL);

	/* check if node's parent has a sibling and return that */
	return (binary_tree_sibling(node->parent));
}
