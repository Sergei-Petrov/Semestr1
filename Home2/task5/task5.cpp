// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №2 , task 5

// Реализовать алгоритм пирамидальной сортировки

#include "stdafx.h"
#include <stdlib.h>

void building(int x[], int j, int n) 
{
	int list = 0;
	int tmp = x[j];
	while (j <= n / 2) 
	{
		list = 2 * j;          
		if ((list < n) && (x[list] < x[list + 1]))	// Выбираем больший лист(правый или левый)
			list++;
		if(tmp >= x[list])	// Если корень больше своих листьев, то выходим, 
			break;			// он стоит на месте.
		x[j] = x[list];     // Иначе меняем их местами
		j = list;			//
    }
	x[j] = tmp;
}
 
void PyramidSort(int x[], int n) 
{
	int tmp;
	for (int i = n / 2; i >= 0; i--)	// Строим
		building(x, i, n - 1);			// дерево
	printf("\n");
	for (int i = n - 1; i > 0; i--) 
	{
		tmp = x[0];				// Меняем местами первый и последний элемеент.
		x[0] = x[i];			// Потом восстанавливаем баланс дерева, не трогая последний элемент.
		x[i] = tmp;				// Он является большим и стоит уже на своём месте.
		building(x, 0, i - 1);	//
	}
}

int main()
{
	const int n = 10;
	int a[n];
	for (int i = 0; i <= n - 1; i++)
	{
		a[i] = rand() % 20;
	}
	printf("Source array : ");
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	PyramidSort(a, n);
	printf("The resulting array : ");
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%d ", a[i]);
	}
	scanf("%");
	return 0;
}