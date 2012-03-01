// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group є143

// homework є11 , task 1

// –еализовать синтаксический анализатор, разбирающий арифметические выражени€ методом рекурсивного спуска.
// ¬ходной поток составл€ют числа, разбираемые лексическим анализатором из прошлой домашней работы, и знаки 
// операций {+, -, /, *}

#include "stdafx.h"
#include <iostream>
#include "syntax.h"

using namespace std;

const int length = 100;

int main()
{
	printf("Enter expression\n");
	char string[length];
	gets(string);
	if(syntax(string))
		printf("true");
	else
		printf("false");
	cin.get();
	return 0;
}