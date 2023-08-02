#include "binary_trees.h"

/**
 * bt_height - Recursively calculates height of a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree, -1 if the tree is NULL.
 **/
size_t bt_height(const binary_tree_t *tree)
{
	int left_height	 = 0;
	int right_height = 0;

	if (tree == NULL) /* empty node */
		return (-1);

	left_height	 = bt_height(tree->left);
	right_height = bt_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_balance - Calculates the balance factor of a
 * binary tree node.
 *
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The balance factor of the binary tree node,
 * or 0 if the node is NULL.
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL) /* empty node */
		return (0);

	/* to find the balace factor, we subtract the height */
	/* of the right child from that of the left child */
	return (bt_height(tree->left) - bt_height(tree->right));
}
