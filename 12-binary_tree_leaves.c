#include "binary_trees.h"

/**
 * binary_tree_leaves - function that counts the leaves in a binary tree
 * @tree: pointer node binary tree
 * Return: Number the leaves in a binary tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t num_leaf = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		num_leaf += 1;
	num_leaf += binary_tree_leaves(tree->left);
	num_leaf += binary_tree_leaves(tree->right);
	return (num_leaf);
}
