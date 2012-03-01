#include "stdafx.h"
#include "tree.h"
#include <iostream>

void dob(Tree *&tr)
{
	int x = 0;
	printf("Enter value : ");
	scanf("%d", &x);
	add(tr, x);
}

void udal(Tree *&tr)
{
	int x = 0;
	printf("Enter value : ");
	scanf("%d", &x);
	delElement(tr, x);
}

void prov(Tree *tr)
{
	int x = 0;
	printf("Enter value : ");
	scanf("%d", &x);
	check(tr, x);
}

int main()
{
	Tree *tr = NULL;
	bool flag = true;
	while (flag)
	{
		printf("\n0 - exit\n1 - add value to set\n2 - remove value from set\n3 - checking\n");
		printf("4 - increasing output\n5 - decreasing output\n\n");
		int a;
		scanf("%d", &a);
		printf("\n");
		switch (a)
		{
			case 0 : flag = false; del(tr); break;
			case 1 : dob(tr); break;
			case 2 : udal(tr); break;
			case 3 : prov(tr); break;
			case 4 : symmUp(tr); printf("\n"); break;
			case 5 : symmDown(tr); printf("\n"); break;
			default : printf("ERROR"); break;
		}
	}
	std::cin.get();
	return 0;
}
