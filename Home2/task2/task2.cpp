// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №2 , task 2

// Реализовать возведение в целую степень (с логарифмической сложностью алгоритма)

#include "stdafx.h"

int pow(int a, int n)
{
	if (n == 0)
		return 1;
	else if (n % 2 == 1)
		return pow(a, n - 1) * a;
	else
	{
		int b = pow(a, n / 2);
		return b * b;
	}
}

int main()
{
	printf("Enter a : ");
	int a = 0;
	scanf("%d", &a);
	printf("Enter n : ");
	int n = 0;
	scanf("%d", &n);
	printf("a ^ n = %d", pow(a, n));
	scanf("%");
	return 0;
}
