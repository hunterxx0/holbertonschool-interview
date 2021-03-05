#include "lists.h"
/**
 * checkPalin - checks if a linked list is palindrome
 *
 * @left: left node
 * @right: right node
 * Return: 0 or 1
 */
int checkPalin(listint_t **left, listint_t *right)
{
	if (right == NULL)
	{
		return (1);
	}

	int result = checkPalin(left, right->next) &&
	((*left)->n == right->n);

	(*left) = (*left)->next;

	return (result);
}

/**
 * is_palindrome - checks if a linked list is palindrome
 *
 * @head: Head node
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{
	return (checkPalin(head, *head));
}
