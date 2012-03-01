#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "list.h"

list *create(int x)
{
	list *tmp = new list;
	tmp->value = x;
	tmp->next = NULL;
	return tmp;
}

void add(list *&l, int x)
{
	if(l == NULL)
		l = create(x);
	else
	{
		list *tmp = new list;
		tmp->value = x;
		tmp->next = NULL;
		list *p = l;
		if (p->value >= x)
		{
			tmp->next = p;
			p = tmp;
		}
		else
		{
			while (p->next != NULL)
			{
				if ((p->value <= x) && (p->next->value >=x))
				{
					tmp->next = p->next;
					p->next = tmp;
					break;
				}
				p = p->next;
			}
			if (p->next == NULL)
				p->next = tmp;
		}
	}
	printf("Adding the value was successful");
}

void del(list *&l)
{
	while (l != NULL)
	{
		list *tmp = l;
		l = tmp->next;
		delete(tmp);
	}
}

void print(list *l)
{
	system("cls");
	if(l == NULL)
		printf("The list is empty");
	else
		printf("List : ");
		while (l != NULL)
		{
			printf("%d ", l->value);
			l = l->next;
		}
	printf("\n");
	std::cin.get();
	std::cin.get();
}

list *search(list *l, int x)
{
	if(l != NULL)
		while ((l != NULL) && (x != l->value))
			l = l->next;
	return l;
}

void der(list *&l, int x)
{
	list *p = l;
	if(p == NULL)
	{
		printf("The list is empty");
	}
	else
	{
		list *tmp = search(p, x);
		if (tmp == NULL)
		{
			printf("Value is not found");
		}
		else
		{
			while (p->next != tmp)
				p = p->next;
			p->next = tmp->next;
			delete(tmp);
			printf("Deleting the value was successful");
		}
	}
}