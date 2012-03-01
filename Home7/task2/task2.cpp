// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №7 , task 2

// Реализовать алгоритмы для работы с хэш-таблицей (разрешение коллизий методом цепочек). 
// По данному тексту (читается из файла, не ограничен по размеру) посчитать число использований каждого слова

#include "stdafx.h"
#include <iostream>
#include "hashtab.h"

int main()
{
	FILE *file;
	file = fopen("txt.txt", "r");
	while(!feof(file))
	{
		char string[12];
		fscanf(file, "%s", string);
		addHash(string);
	}
	printHash();
	delHash();
	std :: cin.get();
	return 0;
}