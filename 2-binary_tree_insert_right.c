#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserting a node as the right-child.
 * @parent: A pointer to a node to insert the right child in.
 * @value: The value to store in the node.
 * Return: A pointer to to created node or NULL on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node = NULL;

	if (parent == NULL || value == '\0')
		return (NULL);

	n_node = malloc(sizeof(binary_tree_t));
	if (n_node == NULL)
		return (NULL);

	n_node->n = value;
	n_node->parent = parent;
	n_node->left = NULL;
	n_node->right = NULL;

	if (parent->right != NULL)
	{
		n_node->right = parent->right;
		n_node->right->parent = n_node;
	}
	parent->right = n_node;
	return (n_node);
}
