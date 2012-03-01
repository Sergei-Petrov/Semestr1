// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �7 , task 2

// ����������� ��������� ��� ������ � ���-�������� (���������� �������� ������� �������). 
// �� ������� ������ (�������� �� �����, �� ��������� �� �������) ��������� ����� ������������� ������� �����

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