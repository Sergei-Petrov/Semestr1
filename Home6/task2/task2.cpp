// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �6 , task 2

// �� ������ ������� ��������������� ��������� ��������� ��� ��������. ������ ������� �������� � ����� � ���� 
// (<��������> <�������1> <�������2>), ��� <�������1> � <�������2> ���� ����� ���� ���������, ���� �������. 
// ��������, ��������� (1 + 1) * 2 �������������� � ���� (* (+ 1 1) 2). ������ �������������� �������� +, -, *, / 
// � ����� ����� � �������� ����������. ��������� ��������� ������ � ����� ����, ����������� ��� (�� ����������� ��� ��, 
// ��� � �����), � ��������� �������� ��������� ������� ������. ����� ���� ������� ������� ungetc (���� �� '(', ����������
// ������ � ����� � ������ ����� fscanf-��). ����� �������, ��� ������� ���� ���������. ������ - �� �������� ����� 
// (* (+ 1 1) 2) ����� ���������� ( * ( + 1 1 ) 2 ) � ���������� 4

#include "stdafx.h"
#include <iostream>
#include "tree.h"

using namespace std;

const int length = 30;

void reading(char string[])
{
	FILE *file;
	file = fopen("text.txt", "r");
	fgets(string, length, file);
	fclose(file);
}

int calculate(Tree *tr)
{
	switch (tr->value)
	{
		case '+' : return calculate(tr->left) + calculate(tr->right); break; 
		case '-' : return calculate(tr->left) - calculate(tr->right); break;
		case '*' : return calculate(tr->left) * calculate(tr->right); break;
		case '/' : return calculate(tr->left) / calculate(tr->right); break;
		default : return tr->value - '0'; break;
	}
}

int main()
{
	Tree *tr = NULL;
	char string[length];
	reading(string);
	printf("In file : %s\n", string);
	int count = 0;
	add(tr, string, count);
	printf("Rezult = %d", calculate(tr));
	del(tr);
	cin.get();
	return 0;
}