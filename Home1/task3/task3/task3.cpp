// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �1 , task 3

// ��� ������ ����� ����� x[1]...x[m+n], ��������������� ��� ���������� ���� ��� ��������: 
// ������ x[1]...x[m] ����� m � ����� x[m+1]...x[m+n] ����� n. �� ��������� �������������� 
// ��������, ����������� ������ � �����.

#include "stdafx.h"
#include <cstdlib>

void swap(int a[], int l, int r)
{
	while (l <= r)
	{
		int t = a[l];
		a[l] = a[r];
		a[r] = t;
		l++;
		r--;
	}
}

int main()
{
	const int m = 4;
	const int n = 5;
	int a[n + m];
	for (int i = 0; i <= n + m - 1; i++)
	{
		int c = rand() % 20 ; 
                a[i] = c;
	}
	printf("Source array : ");
	for (int i = 0; i <= n + m - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	swap(a, 0, n + m - 1);
	swap(a, 0, n - 1);
	swap(a, n, n + m - 1);
	printf("The resulting array : ");
	for (int i = 0; i <= n + m - 1; i++)
	{
		printf("%d ", a[i]);
	}
	scanf("%");
	return 0;
}
