// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №10 , task 2

// Реализовать конечный автомат по разбору чисел с плавающей точкой.

#include "stdafx.h"
#include <iostream>
#include "isDouble.h"

using namespace std;

int main()
{
	char *string[100];
	gets(*string);
	if (checkDouble(*string))
		printf("Yes");
	else
		printf("No");
	cin.get();
	return 0;
}

