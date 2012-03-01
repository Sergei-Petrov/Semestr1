#include "stdafx.h"
#include <stdlib.h>

int main()
{
	const int n = 5;
	int a[n][n];
	printf("Source array : \n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = rand() % 10;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("\n");
	int count;
	int k = 0;
	int i = n / 2;
	int j = n / 2;
	while (k < n - 1)
	{
		for (int b = 0; b < k; b++)
			printf("%d ",a[i++][j]);
		for (int b = 0; b < k; b++)
			printf("%d ",a[i][j++]);
		k++;
		for (int b = 0; b < k; b++)
			printf("%d ",a[i--][j]);
		for (int b = 0; b < k; b++)
			printf("%d ",a[i][j--]);
		k++;
	}
	scanf("%*s");
	return 0;
}

