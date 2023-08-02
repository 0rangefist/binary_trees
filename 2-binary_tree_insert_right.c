#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as the right
 * child of a parent node.
 *
 * @parent: Pointer to the parent node where the new node will
 * be inserted.
 * @value: Value to be stored in the new node.
 *
 * Return: Pointer to the newly created binary tree node,
 *         or NULL if memory allocation fails or if parent is NULL.
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent == NULL) /* can't create a child node */
		return (NULL);

	/* attempt to create a new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL) /* alloc failed */
		return (NULL);
	/* assign the new node a value */
	new_node->n = value;

	/* check if parent already has a right-child*/
	if (parent->right != NULL)
	{ /* make old right-child the right child of the new node */
		new_node->right = parent->right;

		/* make the new node the parent */
		new_node->right->parent = new_node;
	}

	parent->right = new_node;

	return (parent->right);
}
