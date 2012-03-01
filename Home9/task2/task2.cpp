// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №9 , task 2

// Реализовать алгоритм Рабина-Карпа поиска подстроки в строке.

#include "stdafx.h"
#include <iostream>

using namespace std;

void check(int hash, int key, int count, int number, char string[], char substring[])
{
	if(key == hash)
	{
		bool flag = true;
		for(int i = 0; i < number && flag; i++)
			if(string[count++] != substring[i])
				flag = false;
		if (flag)
			printf("%d ", count - number + 1);
	}
}

void rabinkarpa(char string[], char substring[])
{
	int hash = 0;
	int number = 0;
	while(substring[number] != '\0')
		hash = hash + substring[number++];
	int key = 0;
	for(int i = 0; i < number; i++)
		key = key + string[i];
	int count = 0;
	while(string[count + number - 1] != '\0')
	{
		check(hash, key, count, number, string, substring);
		key = key - string[count] + string[count++ + number];
	}
}

int main()
{
	char string[50];
	char substring[10];
	gets(string);
	gets(substring);
	rabinkarpa(string, substring);
	cin.get();
	return 0;
}
