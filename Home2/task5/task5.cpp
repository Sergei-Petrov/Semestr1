// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �2 , task 5

// ����������� �������� ������������� ����������

#include "stdafx.h"
#include <stdlib.h>

void building(int x[], int j, int n) 
{
	int list = 0;
	int tmp = x[j];
	while (j <= n / 2) 
	{
		list = 2 * j;          
		if ((list < n) && (x[list] < x[list + 1]))	// �������� ������� ����(������ ��� �����)
			list++;
		if(tmp >= x[list])	// ���� ������ ������ ����� �������, �� �������, 
			break;			// �� ����� �� �����.
		x[j] = x[list];     // ����� ������ �� �������
		j = list;			//
    }
	x[j] = tmp;
}
 
void PyramidSort(int x[], int n) 
{
	int tmp;
	for (int i = n / 2; i >= 0; i--)	// ������
		building(x, i, n - 1);			// ������
	printf("\n");
	for (int i = n - 1; i > 0; i--) 
	{
		tmp = x[0];				// ������ ������� ������ � ��������� ��������.
		x[0] = x[i];			// ����� ��������������� ������ ������, �� ������ ��������� �������.
		x[i] = tmp;				// �� �������� ������� � ����� ��� �� ���� �����.
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