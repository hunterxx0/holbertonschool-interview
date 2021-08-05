#include "search.h"
/**
* last_cycle - last_cycle function
*
* @oldn: pointer to the head of the skip list to search in
* @value: the value to search for
* Return: Node or None
*/
skiplist_t *last_cycle(skiplist_t *oldn, int value)
{
int idx = 0;
skiplist_t *tmp = oldn;

while (tmp->next)
tmp = tmp->next;

idx = oldn->index;
printf("Value found between indexes [%i] and [%i]\n", idx,
(int)tmp->index);
tmp = oldn;
while (tmp)
{
printf("Value checked at index [%i] = [%i]\n", (int)tmp->index, tmp->n);
if (tmp->n == value)
return (tmp);
tmp = tmp->next;
}
return (NULL);
}
/**
* match - match function
*
* @list: pointer to the head of the skip list to search in
* @oldn: pointer to the head of the portion list to search in
* @tmp: pointer to the tail of the portion list to search in
* @v: the value to search for
* Return: Node or None
*/
skiplist_t *match(skiplist_t *list, skiplist_t *oldn, skiplist_t *tmp, int v)
{
int idx = 0, sq = 0, l = 0;

if (oldn)
idx = oldn->index;
printf("Value found between indexes [%i] and [%i]\n", idx,
(int)tmp->index);
sq = (int)tmp->index;
if (oldn)
tmp = oldn;
else
tmp = list;
while (l < sq)
{
printf("Value checked at index [%i] = [%i]\n", (int)tmp->index, tmp->n);
if (tmp->n == v)
return (tmp);
tmp = tmp->next;
l++;
}
return (NULL);
}
/**
* linear_skip - Looking for a specific value in a singly linked
*
* @list: Integer
* @value: Index of the node in the list
* Return: Node or None
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *tmp = NULL, *oldn = NULL;

if (!list)
return (NULL);
tmp = list->express;
while (tmp)
{
printf("Value checked at index [%i] = [%i]\n", (int)tmp->index, tmp->n);
if (tmp->n > value)
{
tmp = match(list, oldn, tmp, value);
if (tmp)
return (tmp);
else
return (NULL);
}

oldn = tmp;
tmp = tmp->express;
}
if (!tmp)
{
tmp = last_cycle(oldn, value);
if (tmp)
return (tmp);
else
return (NULL);

}
return (NULL);
}
