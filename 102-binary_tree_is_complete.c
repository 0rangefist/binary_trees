#include "11-binary_tree_size.c"
#include "9-binary_tree_height.c"
#include "binary_trees.h"

/**
 * is_level_far_left - Checks if the level is as far
 * left as possible
 *
 * @level: The level of the tree to visit.
 * @tree: Pointer to the current node in the binary tree.
 * @num_of_nodes: number of nodes on the level
 *
 * Return: 1 if as far left as possible or 0 otherwise.
 **/
int is_level_far_left(size_t level, const binary_tree_t *tree,
					  size_t *num_of_nodes)
{
	size_t left_nodes = 0, right_nodes = 0;
	int left_result, right_result;

	if (tree == NULL) /* null node */
		return (0);

	if (level == 1) /* base case */
	{
		(*num_of_nodes)++;
		return (1);
	}

	left_result	  = is_level_far_left(level - 1, tree->left, &left_nodes);
	right_result  = is_level_far_left(level - 1, tree->right, &right_nodes);
	*num_of_nodes = left_nodes + right_nodes;
	return (left_result && right_result && left_nodes >= right_nodes);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is a complete tree.
 *
 * A complete binary tree is a binary tree where every level,
 * except possibly the last, is completely filled, and all nodes
 * are as far left as possible.
 *
 * @tree: Pointer to the root node of the binary tree to check.
 *
 * Return: 1 if the binary tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t tree_height						   = 0;
	size_t tree_size						   = 0;
	size_t last_level_size					   = 0;
	size_t last_level_index					   = 0;
	size_t expected_tree_size_minus_last_level = 0;

	/* if a complete tree, last level should be as far left as possible */
	/* find the index number of the last level */
	tree_height		 = binary_tree_height(tree);
	last_level_index = tree_height + 1;

	/* find if the level is far left as possible & the size of the level */
	if (is_level_far_left(last_level_index, tree, &last_level_size))
	{
		/* a complete binary tree is perfect up till the last-but-one level */
		/* check if the tree up till the last-but-one level is perfect */
		expected_tree_size_minus_last_level = (1 << (tree_height)) - 1;
		tree_size = binary_tree_size(tree);

		if (expected_tree_size_minus_last_level == tree_size - last_level_size)
		{
			/* we have all the levels before the last being perfect */
			return (1);
		}
	}

	return (0);
}
