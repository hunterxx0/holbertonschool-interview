#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - inserts an element in a sorted listint_t list
 * @head: pointer to head of list
 * @n: new node number
 * Return: new node
 */
listint_t *insert_node(listint_t **head, int n)
{

	listint_t *tmp = NULL, *z = (listint_t *)malloc(sizeof(listint_t));
	int flag = 0;

	if (!z || !head || !*head)
		return (NULL);
	tmp = *head;
	if (tmp->n < n)
	{
		while (tmp->next)
		{
			if (tmp->next && tmp->next->n > n)
				break;
			tmp = tmp->next;
		}
		flag = 1;
	}
	if (flag)
	{
	z->n = n;
	z->next = tmp->next;
	if (tmp->n != n)
		tmp->next = z;
	}
	else
	{
		z->n = n;
		z->next = *head;
		*head = z;
	}
	return (z);
}
