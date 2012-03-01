// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №10 , task 1

// Многочлен с целыми коэффициентами представлен в виде связного списка: в каждом элементе хранится степень x и 
// ненулевой коэффициент. Описать типа данных, реализовать следующие функции:
// - equals(p,q) -- проверка равенства многочленов p и q;
// - value(p,x) -- вычисление значения многочления в точке x
// - add(p,q,r) -- вычисление суммы многочленов r = p + q;
// Реализовать интерфейс пользователя, позволяющий выполнять указанные операции над многочленами и выводить 
// полученные результаты.

#include "stdafx.h"
#include <iostream>
#include "list.h"

using namespace std;

void addition(list *&l)
{
	char string[20];
	gets(string);
	int count = 0;
	int degree = 0;
	int coef = 0;
	while (string[count] != '\0')
	{
		if (string[count] == '-')
		{
			string[count++] = ' ';
			coef = -1;
		}
		else if (string[count] == '+')
		{
			string[count++] = ' ';
			coef = 1;
		}
		else
			coef = 1;
		if (string[count] - '0' >= 0 && string[count] - '0' < 10)
		{
			int x = 0;
			sscanf(string, "%d", &x);
			coef = coef*x;
			string[count++] = ' ';
			while (string[count] - '0' >= 0 && string[count] - '0' < 10)
				string[count++] = ' ';
		}
		if (string[count] != 'x')
			degree = 0;
		else
		{
			string[count++] = ' ';
			if (string[count] != '^')
				degree = 1;
			else
			{
				string[count++] = ' ';
				sscanf(string, "%d", &degree);
				while (string[count] - '0' >= 0 && string[count] - '0' < 10)
					string[count++] = ' ';
			}
		}
		add(l, coef, degree);
	}
}

void equals()
{
	list *p = NULL;
	list *q = NULL;
	printf("Enter first polynomial:\n");
	addition(p);
	printf("Enter second polynomial:\n");
	addition(q);
	while (p != NULL && q != NULL)
		if (p->coef == q->coef && p->degree == q->degree)
		{
			p = p->next;
			q = q->next;
		}
		else
			break;
	if (p == NULL && q == NULL)
		printf("Polynomials are equal");
	else
		printf("Polynomials are not equal");
	del(p);
	del(q);
	cin.get();
}

int calc(int x, int coef, int degree)
{
		int rez = 1;
		for (int i = 1; i <= degree; i++)
		{
			rez = rez * x;
		}
		return rez * coef;
}

void value()
{
	list *p = NULL;
	printf("Enter polynomial:\n");
	addition(p);
	printf("Enter x :\n");
	int x = 0;
	scanf("%d", &x);
	int rezult = 0;
	while (p != NULL)
	{
		rezult = rezult + calc(x, p->coef, p->degree);
		p = p->next;
	}
	printf("Rezult = %d\n", rezult);
	del(p);
	cin.get();
	cin.get();
}

void plus()
{
	list *r = NULL;
	list *p = NULL;
	list *q = NULL;
	printf("Enter first polynomial:\n");
	addition(p);
	printf("Enter second polynomial:\n");
	addition(q);
	while (p != NULL && q != NULL)
	{
		if (p->degree == q->degree)
		{
			add(r, p->coef + q->coef, p->degree);
			p = p->next;
			q = q->next;
		}
		else if (p->degree > q->degree)
		{
			add(r, p->coef, p->degree);
			p = p->next;
		}
		else
		{
			add(r, q->coef, q->coef);
			q = q->next;
		}
	}
	while (p != NULL)
	{
		add(r, p->coef, p->degree);
		p = p->next;
	}
	while (q != NULL)
	{
		add(r, q->coef, q->degree);
		q = q->next;
	}
	printf("Rezult : ");
	print(r);
	del(p);
	del(q);
	del(r);
	cin.get();
}

int main()
{
	int k = 0;
	bool flag = true;
	while (flag)
	{
		printf("\n\n0 - comparison of the polynomials\n1 - count value\n2 - addition of polynomials\n3 - exit\n");
		scanf("%d", &k);
		cin.get();
		switch (k)
		{
			case 0 :
				equals();
				break;
			case 1 :
				value();
				break;
			case 2 :
				plus();
				break;
			case 3 :
				flag = false;
				break;
		}
	}
	return 0;
}