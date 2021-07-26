#include "binary_trees.h"
/**
 * avalint - builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree.
 */
avl_t *newnod(int n, avl_t *parr)
{
	avl_t *node = NULL;

	node = (struct binary_tree_s *)malloc(sizeof(struct binary_tree_s));
	node->n = n;
	node->parent = parr;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
/**
 * avalint - builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree.
 */
avl_t *avalint(int *arr, size_t size, avl_t *parr)
{
	int c = 0, i = 0, *l = NULL, *r = NULL, s1 = 0,
	s2 = 0, mid = 0;
	avl_t *node = NULL;

	if (!arr || size <= 0)
		return (NULL);

	l = malloc(sizeof(int) * (size / 2));
	r = malloc(sizeof(int) * (size - ((size / 2) + 1)));

	if (size % 2)
		mid = (int)size / 2;		
	else
		mid = (int)size / 2 - 1;
	for (; c < (int)size; c++)
	{
		if (c < mid)
			l[c] = arr[c];
		else if ( c == mid) {
			s1 = c;
			s2 = (int)size - (c + 1);
		}
		else {
			r[i] = arr[c];
			i++;
		}
	}
	node = newnod(arr[s1], parr);
	node->left = avalint(l, s1, node);
	node->right = avalint(r, s2, node);
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

	root = avalint(array, size, NULL);
	return(root);
}
