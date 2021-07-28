#include "binary_trees.h"
/**
 * newnod - builds an AVL tree from an array
 * @n: Node data
 * @parr: a pointer to the parent element of the node
 *
 * Return: a pointer to the created node.
 */
avl_t *newnod(int n, avl_t *parr)
{
	avl_t *node = NULL;

	node = (struct binary_tree_s *)malloc(sizeof(struct binary_tree_s));
	if (!node)
		return (NULL);
	node->n = n;
	node->parent = parr;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
/**
 * avalint - builds an AVL tree from an array
 * @arr: a pointer to the first element of the array to be converted
 * @parr: a pointer to the parent element of the node
 * @first: the number of the first element in the array
 * @last: the number of the last element in the array
 *
 * Return: a pointer to the root node of the created AVL tree.
 */
avl_t *avalint(int *arr, avl_t *parr, int first, int last)
{
	avl_t *node = NULL;
	int mid = (first + last) / 2;

	if (first > last)
		return (NULL);
	node = newnod(arr[mid], parr);
	if (!node)
		return (NULL);
	if (mid != first)
		node->left = avalint(arr, node, first, mid - 1);
	if (mid != last)
		node->right = avalint(arr, node, mid + 1, last);
	return (node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (!array || !size)
		return (NULL);

	root = avalint(array, NULL, 0, (int)size - 1);
	return (root);
}
