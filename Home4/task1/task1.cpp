// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group №143

// homework №4 , task 1

// Даны две строки. Определить, можно ли, переставляя символы в первой строке, получить вторую строку

#include "stdafx.h"
#include <stdio.h>

void QSort(char a[], int left, int right)
{
	if(left < right)
	{ 
		char point = a[left];
		int i = left;
		int j = right;
		while(i < j)
		{
			while(a[i] <= point && i < right)
				i++;
			while(a[j] >= point && j > left)
				j--;
			if(i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		int temp = a[left];
		a[left] = a[j];
		a[j] = temp;
		QSort(a, left, j - 1);
		QSort(a, j + 1, right);
	}
}

int length(char a[])	
{
	int i = 0;
	int k = 0;
	while(a[i] != NULL)
	{
		i++;
		k++;
	}
	return k;
}

void control(char str[], char st[])
{
	int a = length(str);
	int b = length(st);
	if (a == b)
	{
		QSort(str, 0, a);
		QSort(st, 0, b);
		bool flag = true;
		for(int i = 0; (i < a) && (flag); i++)
			if (str[i] != st[i])
			{
				printf("NO");
				flag = false;
			}
		if (flag)
			printf("YES");
	}
	else
		printf("NO");
}
int main()
{
	char str[20];
	char st[20];
	printf("Enter first string : ");
	gets(str);
	printf("Enter second string : ");
	gets(st);
	control(str, st);
	scanf("%*s");
	return 0;
}

