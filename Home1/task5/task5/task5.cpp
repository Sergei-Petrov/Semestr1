// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �1 , task 5

// �������� ��������� �������� ������� ������ � �������� ������ (�.�. ����� ����������� ������ ����� 
// ����� ����������� � ����������� ������� ����������� ������).

#include "stdafx.h"

int main()
{
	char s[50];
	printf("Enter a string: ");
	scanf("%s", s);
	int i = 0;
	int a = 0;
	while ((s[i] != NULL) && (a >= 0))
	{
		if (s[i] == '(')
			a++;
		else if (s[i] == ')')
			a--;
		i++;
	}
	if (a == 0)
		printf("All right");
	else
		printf("Error");
	scanf("%");
	return 0;
}

