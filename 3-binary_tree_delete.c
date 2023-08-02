#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: Pointer to the root node of the binary tree to be deleted.
 **/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL) /* do nothing if already NULL */
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
