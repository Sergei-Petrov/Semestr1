// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №2 , task 1

// Реализовать рекурсивный и итеративный подсчет чисел Фибоначчи

#include "stdafx.h"

int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n < 3)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	printf("Enter n : ");
	int n = 0;
	scanf("%d", &n);
	printf("Fibonacci number : %d", fib(n));
	scanf("%");
	return 0;
}