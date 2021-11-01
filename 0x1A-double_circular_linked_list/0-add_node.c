#include "list.h"

/**
 * newnode(:)? (- create a new node)?
 *
 * @str: node string
 * Return: new node
 */
List *newnode(char *str)
{
	List *nd = NULL;

	nd = malloc(sizeof(List *));
	if (!nd)
		return (NULL);
	nd->str = str;
	nd->next = NULL;
	nd->prev = NULL;
	return (nd);
}

/**
 * add_node_end(:)? (- Add a new node to the end of a dcll)?
 *
 * @list: input list
 * @str: node string
 * Return: new node
 */
List *add_node_end(List **list, char *str)
{
	List *nd = NULL, *tmp;

	nd = newnode(str);
	if (!nd)
		return (NULL);
	if (!*list)
		*list = nd;
	else
	{
		tmp = (*list)->prev;
		(*list)->prev = nd;
		nd->next = (*list);
		nd->prev = tmp;
		if (tmp)
			tmp->next = nd;
		else
		{
			(*list)->next = nd;
			nd->prev = (*list);
		}
	}
	return (nd);
}

/**
 * add_node_begin(:)? (- Add a new node to the start of a dcll)?
 *
 * @list: input list
 * @str: node string
 * Return: new node
 */
List *add_node_begin(List **list, char *str)
{
	List *nd = NULL, *tmp;

	nd = newnode(str);
	if (!nd)
		return (NULL);
	if (!*list)
		*list = nd;
	else
	{
		tmp = (*list)->prev;
		(*list)->prev = nd;
		nd->next = (*list);
		nd->prev = tmp;
		if (tmp)
			tmp->next = nd;
		else
		{
			(*list)->next = nd;
			nd->prev = (*list);
		}
		(*list) = nd;
	}
	return (nd);
}
