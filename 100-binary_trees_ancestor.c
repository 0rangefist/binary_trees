#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the common ancestor of two
 * nodes in a binary tree.
 *
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the common ancestor node, or NULL if
 * no common ancestor, or if either input node is NULL.
 **/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *second_backup = second;

	if (first == NULL || second == NULL)
		return (NULL); /* check for NULL nodes */

	if (first == second) /* check if nodes are the same */
		return ((binary_tree_t *) first);

	if (first == second->parent) /* check if 1st is parent of 2nd */
		return (second->parent);

	if (second == first->parent) /* check if 2nd is parent of 1st */
		return (first->parent);

	if (first->parent == second->parent) /* check nodes are siblings */
		return (first->parent);

	/* traverse up the parental lineage of the first node */
	/* compare each parent with a traversal of the parental */
	/* lineage of the second till a match (common anc.) is found */

	while (first != NULL)
	{
		while (second != NULL)
		{
			if (first == second) /* common anc found */
				return ((binary_tree_t *) first);
			second = second->parent;
		}

		first = first->parent;
		second = second_backup; /* reset second node */
	}

	return (NULL); /* no ancestor found */
}
