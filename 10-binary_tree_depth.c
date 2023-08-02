#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a node
 * in a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The depth of a node in the binary tree,
 * or 0 if the tree is NULL.
 **/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL) /* empty node */
		return (0);

	/* to calculate the depth of the current node in the tree, walk */
	/* up fom the node to the root, counting each step of the way */
	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
