// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �7 , task 1

// ������� �������� ������� �� ����������������, ������ ��������� ���������� � ������� �����. 
// ��� �������� � �������� 1, 2 � 3 ������ ������� ��� ������� ��������������, ������ ������ ������� � ����-������, 
// ��� ��� ����� ������� ������� - ���� �������� ��������������, ���� ��� ��������� � �������. �� ��������� ������� 
// ����������, ��� ��������� ��������� ������� ���������� ���������, �.�. ��� �� ������ �� �������� ������� ����, 
// �� � ���������� �������. ������: ����������, ����� ������� ����� ������� ������, � ���� ���� ���������.
// �� �����: ���������� ��������� � ������ ��� �����, ��� ������ ����� - ����� ��������, ������ - ����� ����, 
// � ���� ���� ������� �������. ��������� ������� ������ ��� �����, ��� ������ ����� - ����� ��������, 
// ������ - 1, 2 ��� 3 - ������� �������.

#include "stdafx.h"
#include <iostream>

using namespace std;

void initialization(int spisok[], int number)
{
	for(int i = 0; i < number; i++)
		spisok[i] = 0;
}

int main()
{
	FILE *file;
	file = fopen("txt.txt","r");
	int number = 0;					// ���-�� ���������
	fscanf(file, "%d", &number);
	int *spisok = new int[number];	// ������ ���������. ������+1 - ����� ��������. �������� - ����� ��������, � �������� �������.
	int student = 0;				// ����� ��������
	initialization(spisok, number);
	for(int i = 0; i < number; i++)
	{
		fscanf(file, "%d", &student);
		fscanf(file, "%d", &spisok[student - 1]);
	}
	fclose(file);
	for(int i = 0; i < number ; i++)
	{
		if(spisok[i] == 0)
			printf("%d send down\n", i + 1);
		else
		{
			while((spisok[i] != 1) && (spisok[i] != 2) && (spisok[i] != 3))
				spisok[i] = spisok[spisok[i] - 1];
			printf("%d : %d\n",i + 1, spisok[i]);
		}
	}
	cin.get();
	return 0;
}