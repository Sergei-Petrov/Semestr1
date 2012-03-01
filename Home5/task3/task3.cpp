// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №5 , task 3

// Вывести на консоль все однострочные комментарии С++ (вида // комментарий) из входного файла
// (вместе с символами "//"). До комментария в строке может быть значимый текст, его выводить не надо, 
// строки без комментариев не выводить. Конец строки представляется символом '\n', могут быть полезны 
// функции fgetc и feof.

#include "stdafx.h"
#include <iostream>
#include <string.h>

const int length = 20;

void initialization(char string[])
{
	for (int i = 0; i < length; i++)
	{
		string[i] = '\n';
	}	
}

void print(char string[], int count)
{
	while (string[count] != '\n') 
	{
		printf("%c", string[count++]);
	}
	printf("\n");
}

void check()
{
	FILE *file;
	file = fopen("text.txt", "r");
	char string[length];
	while (!feof(file))
	{
		fgets(string, length, file);
		int count = 2;
		while (string[count] != '\n')
		{
			if ((string[count - 1] == '/') && (string[count - 2] == '/'))
			{
				print(string, count);
			}
			count++;
		}
		initialization(string);
	}
	fclose(file);
}

int main()
{
	check();
	std::cin.get();
	return 0;
}

