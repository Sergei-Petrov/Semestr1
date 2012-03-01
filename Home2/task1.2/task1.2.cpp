// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №2 , task 1

// Реализовать рекурсивный и итеративный подсчет чисел Фибоначчи

#include "stdafx.h"

int main()
{
	printf("Enter n : ");
	int n;
	scanf("%d", &n);
	if (n ==0)
		printf("Fibonacci number : 0");
	else if (n == 1)
		printf("Fibonacci number : 1");
	else
	{
		int i = 1;
		int a = 0; //значение числа фибоначчи при n = 0
		int b = 1; //значение числа фибоначчи при n = 1
		int sum = 0;
		while (i < n)
		{
			sum = a + b;
			a = b;
			b = sum;
			i++;
		}
		printf("Fibonacci number : %d", sum);
	}
	scanf("%");
	return 0;
}