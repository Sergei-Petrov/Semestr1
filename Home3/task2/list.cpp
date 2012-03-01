#include "stdafx.h"
#include "list.h"

list *create(int n)
{
	list *tmp = new list;
	list *l = tmp;
	tmp->value = 1;
	tmp->next = tmp;
	for(int i = 2; i <= n; i++)
	{
		list *q = new list;
		q->value = i;
		l->next = q;
 		q->next = tmp;
 		l = q;
	}
	return tmp;
}

void del(list *l, int pos, int kol, int j, bool &flag)
{
	list *tmp = l;
	int k = 0;
	int i = 1;
	while (k < kol - 1)
	{
		while (i < j - 1)
		{
			i++;
			tmp = tmp->next;
		}
		i = 0;
		k++;
		list *l = tmp->next;
		tmp->next = tmp->next->next;
		delete l;
	}
	if (tmp->value == pos)
	{
		flag = false;
		printf("Need delete each %d\n", j);
	}
	delete tmp;
}
