// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �1 , task 10

// ����������� ���������, �����������, �������� �� ������ ����������.
#include "stdafx.h"

int main()
{
	char s[20];
	printf("Enter string : ");
	scanf("%s", s);
	int i = 0;
	int length = 0;
	while (s[i] != NULL)
	{
		length++;
		i++;
	}
	bool flag = true;
	for (i = 0; (i <= length/2 && flag); i++)
	{
		if (s[i] != s[length-1-i])
			flag = false;
	}
	if (flag)
		printf("Palindrome");
	else
		printf("Not a palindrome");
	scanf("%");
	return 0;
}

