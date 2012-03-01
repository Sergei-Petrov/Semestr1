// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №3 , task 1

// Найдите максимальный элемент массива, встречающийся более одного раза (массив неупорядоченный)


#include "stdafx.h"
#include <stdlib.h>

int main()
{
	const int n = 10;
	int a[n];
	for (int i = 0; i <= n - 1; i++)
	{
		a[i] = rand()  % 20;
	}
	printf("Source array : ");
	for (int i = 0; i <= n - 1; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	int k = -2147483648;
	for(int i = 0; i <= n - 1; i++)
	{
		for(int j = i + 1; j <= n - 1; j++)
		{
			if (a[i] == a[j])
				if (k < a[i])
					k = a[i];
		}
	}
	if (k != -2147483648)
		printf("Maximum repeating element : %d", k);
	else
		printf("No a repeating element");
	scanf("%");
	return 0;
}

