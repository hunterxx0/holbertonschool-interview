#include "lists.h"
/**
 * is_palindrome - checks if a linked list is palindrome
 *
 * @head: Head node
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{
	listint_t *h = *head, *tmp = NULL, *last = NULL;
	int c = 0, half = 0, count = 0;

	if (*head)
	{
		while (h)
		{
			c += 1;
			if (!h->next)
				last = h;
			h = h->next;
		}
		count = c;
		half = c/2;
		c = 0;
		h = *head;
		if (h->n != last->n)		
			return (0);
		while (c <= half)
		{
			if (!tmp && c == half - 1 && (count % 2))
				tmp = h->next;
			if (!tmp && c == half - 1 && !(count % 2))
				tmp = h;
			c += 1;
			h = h->next;
		}
		c = 0;
		h = *head;
		while (half)
		{ 
			c += 1;
			h = h->next; 
			if (c == half)
			{
				if (h->n != tmp->n)
					return (0);
				else
				{
					half -= 1;
					h = *head;
					c = 0;
					tmp = tmp->next;
				}
			}	
			if (!tmp)
				break;
			}
		}
	return (1);
}
