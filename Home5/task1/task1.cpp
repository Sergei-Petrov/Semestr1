// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №5 , task 1

// Дан текст, вывести все слова, предварительно оставив в каждом слове только первые вхождения каждой буквы.

#include "stdafx.h"
#include <stdio.h>
#include <iostream>

const int letter = 58;
const int length = 40;

void input(char string[])
{
	printf("Enter text : ");
	gets(string);
}

void initialization(bool a[])
{
	for(int i = 0; i < letter; i++)
	{
		a[i] = true;
	}
}

void print(char string[], bool a[])
{
	int count = 0;
	while (string[count] != NULL)
	{
		if (((string[count] - 'A') < letter) && ((string[count] - 'A') >= 0)) 
		{
			if (a[string[count] - 'A'])
			{
				printf("%c", string[count]);
				a[string[count] - 'A'] = false;
			}
		}
		else
		{
			printf(" ");
			initialization(a);
		}
		count++;
	}
}

int main()
{
	char string[length];
	input(string);
	bool a[letter];
	initialization(a);
	print(string, a);
	std::cin.get();
	return 0;
}