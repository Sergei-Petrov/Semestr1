// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group є143

// homework є1 , task 2

// –еализовать алгоритм нахождени€ неполного частного от делени€ a на b (целые числа),
// использу€ только операции сложени€, вычитани€ и умножени€.

#include "stdafx.h"

int main()
{
	printf("Enter a : ");
	int a = 0;
	scanf("%d", &a);
	printf("Enter b : ");
	int b = 0;
	scanf("%d", &b);
	int k = 0;
	while (a >= b)
	{
		a = a - b;
		k++;
	}
	printf("Incomplete quotient = %d", k); 
	scanf("%");
	return 0;
}

