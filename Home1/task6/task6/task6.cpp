// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �1 , task 6

// ������ ��� ������: S � S1. ����� ���������� ��������� S1 � S ��� ���������.

#include "stdafx.h"

int main()
{
	char s[20];
	char s1[20];
	printf("Enter a string s: ");
	scanf("%s", s);
	printf("Enter a string s1: ");
	scanf("%s", s1);
	int i = 0;
	bool flag = true;
	int k = 0;
	while (s[i] != NULL) 
	{
		if (s[i] == s1[0])
		{
			int j = 1;
			while ((s1[j] != NULL) && (flag))
			{
				if (s1[j] != s[i + j])
				{
					flag = false;
				}
				j++;
			}
			if (flag)
				k++;
		}
		i++;
	}
	printf("Result : %d", k);
	scanf("%");
	return 0;
}

