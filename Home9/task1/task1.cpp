// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №9 , task 1

// Даны 2 текстовых файла. Записать в третий файл только те строки, которые встречаются и в первом, и во втором файлах.

#include "stdafx.h"
#include <iostream>
#include "hashtab.h"

using namespace std;

int main()
{
	FILE *first = fopen("first.txt", "r");
	FILE *second = fopen("second.txt", "r");
	FILE *third = fopen("third.txt", "w");
	char string[50];
	while(!feof(first))
	{
		fscanf(first, "%s", string);
		addHash(string);
	}
	int flag = 0;
	while(!feof(second))
	{
		fscanf(second, "%s", string);
		found(third, string, flag);
	}
	delHash();
	fclose(first);
	fclose(second);
	fclose(third);
	if(flag > 1)
		printf("Strings written to a file");
	else if(flag == 1)
		printf("String written to a file");
	else
		printf("No duplicate string");
	cin.get();
	return 0;
}