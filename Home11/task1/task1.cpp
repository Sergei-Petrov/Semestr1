// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �11 , task 1

// ����������� �������������� ����������, ����������� �������������� ��������� ������� ������������ ������.
// ������� ����� ���������� �����, ����������� ����������� ������������ �� ������� �������� ������, � ����� 
// �������� {+, -, /, *}

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