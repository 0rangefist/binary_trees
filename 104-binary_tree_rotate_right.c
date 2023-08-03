#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 *
 * @tree: Pointer to the root node of the binary tree to rotate.
 *
 * Return: Pointer to the new root node after the right rotation,
 * or NULL if the rotation is not possible
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	/* to rotate a tree right, there must be a left child */
	if (tree == NULL || tree->left == NULL) /* null tree or left child */
		return (NULL);

	/* to rotate right, the left child of root is chosen as pivot */
	pivot = tree->left;

	tree->left = pivot->right;

	if (pivot->right != NULL) /* pivot's right child exists */
		pivot->right->parent = tree;

	/* root becomes the right child of pivot */
	pivot->right = tree;

	/* the root's parent becomes the pivot's parent instead */
	pivot->parent = tree->parent;

	/* the root's parent becomes the pivot */
	tree->parent = pivot;

	return (pivot); /* new root after rotation */
}
