// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №1 , task 11

// Реализовать быструю сортировку (в рекурсивном варианте)

#include "stdafx.h"
#include <cstdlib>

void QSort(int a[], int left, int right)
{
	if(left < right)
	{ 
		int point = a[left];
		int i = left;
		int j = right;
		while(i < j)
		{
			while(a[i] <= point && i < right)
				i++;
			while(a[j] >= point && j > left)
				j--;
			if(i < j)
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		int temp = a[left];
		a[left] = a[j];
		a[j] = temp;
		QSort(a, left, j - 1);
		QSort(a, j + 1, right);
	}
}

int main()
{
	const int N = 10;
	int a[N];
	for (int i = 0; i <= N - 1; i++)
	{
		int c = rand() % 20 ; 
        a[i] = c;
	}
	printf("Source array : ");
	for (int i = 0; i <= N - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	QSort(a, 0, N - 1);
	printf("The resulting array : ");
	for (int i = 0; i <= N - 1; i++)
	{
		printf("%d ", a[i]);
	}
	scanf("%");
	return 0;
}

