// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №4 , task 3

/*	Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:
	0 - exit
	1 - add value to sorted list
	2 - remove value from list
	3 - print list
	Все операции должны сохранять сортированность. Начинаем с пустого списка. */

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "list.h"
void dob(list *&l)
{
	system("cls");
	printf("Enter value : ");
	int x;
	scanf("%d", &x);
	add(l, x);
	std::cin.get();
	std::cin.get();
}

void udal(list *&l)
{
	system("cls");
	printf("Enter value : ");
	int x;
	scanf("%d", &x);
	der(l, x);
	std::cin.get();
	std::cin.get();
}
int main()
{
	list *l = NULL;
	bool flag = true;
	while (flag)
	{
		printf("0 - exit\n1 - add value to sorted list\n2 - remove value from list\n3 - print list\n");
		int a;
		scanf("%d", &a);
		switch (a)
		{
			case 0 : flag = false; del(l); break;
			case 1 : dob(l); break;
			case 2 : udal(l); break;
			case 3 : print(l); break;
			default : break;
		}
		system("cls");
	}
	return 0;
}

