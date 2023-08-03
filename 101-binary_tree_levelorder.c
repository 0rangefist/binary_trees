#include "9-binary_tree_height.c"
#include "binary_trees.h"
#include <stdio.h>

/**
 * visit_level - Recursively visit nodes at a given level in a binary tree.
 *
 * @level: The level of the tree to visit.
 * @tree: Pointer to the current node in the binary tree.
 * @func: Function pointer
 **/
void visit_level(int level, const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL) /* null node */
		return;

	if (level == 1) /* base case */
		func(tree->n);

	if (level > 1)
	{
		/* recusively work down to the level of interest */
		visit_level(level - 1, tree->left, func);
		visit_level(level - 1, tree->right, func);
	}
}

/**
 * binary_tree_levelorder - Perform a level order traversal of
 * a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 * @func: Pointer to the function to be called on each node.
 **/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level;
	size_t tree_height;

	if (tree == NULL || func == NULL) /* empty tree or func */
		return;

	tree_height = binary_tree_height(tree);
	/* level order traversal means visiting nodes level by level */
	/* we loop over the visitation function from level 1 to height */
	for (level = 1; level <= tree_height + 1; level++)
	{
		visit_level(level, tree, func);
	}
}
