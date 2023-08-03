#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree to rotate.
 *
 * Return: Pointer to the new root node after the left rotation,
 * or NULL ifthe rotation is not possible
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	/* to rotate a tree left, there must be a right child */
	if (tree == NULL || tree->right == NULL) /* null tree or right child */
		return (NULL);

	/* to rotate left, the right child of root is chosen as pivot */
	pivot = tree->right;

	tree->right = pivot->left;

	if (pivot->left != NULL) /* pivot's left child exists */
		pivot->left->parent = tree;

	/* root becomes the left child of pivot */
	pivot->left = tree;

	/* the root's parent becomes the pivot's parent instead */
	pivot->parent = tree->parent;

	/* the root's parent becomes the pivot */
	tree->parent = pivot;

	return (pivot); /* new root after rotation */
}
