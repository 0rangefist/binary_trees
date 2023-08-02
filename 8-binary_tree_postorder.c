#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using postorder traversal.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node's value.
 **/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func) /* do nothing, if tree or func is NULL */
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
