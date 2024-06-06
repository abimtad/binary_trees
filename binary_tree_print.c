#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @ch: Buffer
 *
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **ch)
{
	char ltr[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(ltr, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, ch);
	right = print_t(tree->right, offset + left + width, depth + 1, ch);
	for (i = 0; i < width; i++)
		ch[depth][offset + left + i] = ltr[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			ch[depth - 1][offset + left + width / 2 + i] = '-';
		ch[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			ch[depth - 1][offset - width / 2 + i] = '-';
		ch[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;

	height_left = tree->left ? 1 + _height(tree->left) : 0;
	height_right = tree->right ? 1 + _height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **ch;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	ch = malloc(sizeof(*ch) * (height + 1));
	if (!ch)
		return;
	for (i = 0; i < height + 1; i++)
	{
		ch[i] = malloc(sizeof(**ch) * 255);
		if (!ch[i])
			return;
		memset(ch[i], 32, 255);
	}
	print_t(tree, 0, 0, ch);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (ch[i][j] != ' ')
				break;
			ch[i][j] = '\0';
		}
		printf("%ch\n", ch[i]);
		free(ch[i]);
	}
	free(ch);
}
