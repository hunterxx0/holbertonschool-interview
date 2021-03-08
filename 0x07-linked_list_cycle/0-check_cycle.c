#include "lists.h"

/**
 * check_cycle - checks a cycle in a list
 * @l: pointer to list
 * Return: x
 */
int check_cycle(listint_t *l)
{
	listint_t *s, *f;

	f = s = l;
	while (f && s && f->next)
	{
		s = s->next;
		f = f->next->next;
		if (s == f)
			return (1);
	}
	return (0);
}