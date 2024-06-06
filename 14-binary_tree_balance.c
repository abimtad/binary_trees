#include "binary_trees.h"

/**
 * binary_tree_balance - A function that measures the balance factor of a
 * binary tree.
 * @tree: Pointer to root node to calculate balance factor.
 * Return: The balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);
	return (l_height - r_height);
}

/**
 * binary_tree_height - gets the height of a binary tree
 * @tree: root node to draw height from for tree
 * Return: size_t representing height, 0 on failure or NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_size = 0;
	size_t r_size = 0;

	if (!tree)
		return (0);

	l_size += 1 + binary_tree_height(tree->left);
	r_size += 1 + binary_tree_height(tree->right);
	if (l_size > r_size)
		return (l_size);

	return (r_size);
}
