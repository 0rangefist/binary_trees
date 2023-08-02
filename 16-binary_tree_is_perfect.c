#include "11-binary_tree_size.c"
#include "9-binary_tree_height.c"
#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height		  = 0;
	size_t tree_size		  = 0;
	size_t expected_tree_size = 0;

	if (!tree) /* if tree is NULL */
		return (0);

	/* Determine the size and height of the tree */
	tree_size	= binary_tree_size(tree);
	tree_height = binary_tree_height(tree);

	/* Calculate expected tree size of a perfect tree using tree_height */
	expected_tree_size = (1 << (tree_height + 1)) - 1;

	/* Check if tree_size matches expected_tree_size of a perfect tree */
	return (tree_size == expected_tree_size);
}
