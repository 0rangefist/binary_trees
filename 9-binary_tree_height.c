#include "binary_trees.h"

/**
 * bt_recursive_height - Recursively calculates height of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree, -1 if the tree is NULL.
 **/
size_t bt_recursive_height(const binary_tree_t *tree)
{
	int left_height	 = 0;
	int right_height = 0;

	if (tree == NULL) /* empty node */
		return (-1);

	left_height	 = bt_recursive_height(tree->left);
	right_height = bt_recursive_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_height - Calculates the height of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree, 0 if the tree is NULL.
 **/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL) /* empty node */
		return (0);
	else
		return (bt_recursive_height(tree));
}
