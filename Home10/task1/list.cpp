#include "stdafx.h"
#include <stdlib.h>
#include "list.h"

list *create(int coef, int degree)
{
	list *tmp = new list;
	tmp->coef = coef;
	tmp->degree = degree;
	tmp->next = NULL;
	return tmp;
}

void add(list *&l, int coef, int degree)
{
	if(l == NULL)
		l = create(coef, degree);
	else if(degree > l->degree)
	{
		list *tmp = create(coef, degree);
		tmp->next = l;
		l = tmp;
	}
	else
		add(l->next, coef, degree);
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
	int k = 0;
	if(l == NULL)
		printf("The list is empty");
	else
	{
		while (l != NULL)
		{
			if (l->coef != 0)
			{
				if (l->coef != 1 && l->coef != -1 && l->coef > 0)
					if (k == 0)
						printf("%d", l->coef);
					else
						printf("+%d", l->coef);
				else if (l->coef != 1 && l->coef != -1 && l->coef < 0)
					printf("%d", l->coef);
				else if (l->coef == -1 && l->degree != 0)
					printf("-");
				else if (l->degree != 0)
					printf("+");
				if (l->degree != 0)
					if (l->degree == 1)
						printf("x");
					else
						printf("x^%d", l->degree);
				else if(l->coef == -1)
					printf("%d", l->coef);
				else
					printf("+%d", l->coef);
			}
			l = l->next;
			k++;
		}
	}
	printf("\n");
}