// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group �143

// homework �8 , task 2

// � ��������� ������ n �������, ����������� ����� ����� �������� ��������� �����. �� ������ ������ ����� �������� � 
// ��� �������. 1 �������� 1939� ���� �������� ����� ��������� � ��� ������ � ��������� ����� � ������� 1. �����, 
// ������ ���� ��� ����������� �� ������ ������, ��������� ��������� ��������: ����� ���� ��� �� ����������� ������� 
// ���������� ��������� � ������ 1 � �������������.
// �� ������� ����� ������ n - ����� ������� � m - ����� �����.
// ����� ������� ���� ������ � �������:
// i j len
// i � j - ������ �������, len - ����� ������.
// ������: ������� ������ ������� � ������� �������, � ����� � ���������� �� ������� ������������ ������ �� ������ 1.

#include "stdafx.h"
#include <iostream>

using namespace std;

int const first = 0;
int const infinity = 2147483647;

int read(FILE *file)
{
	int tmp = 0;
	fscanf(file, "%d", &tmp);
	return tmp;
}

void initGraph(int *graph[], int city)
{
	for(int i = 0; i < city; i++)
		for(int j = 0; j < city; j++)
			graph[i][j] = 0;
}

void fillGraph(FILE *file, int*graph[], int road)
{
	int k = 0;
	int l = 0;
	for(int i = 0; i < road; i++)
	{
		fscanf(file, "%d", &k);
		fscanf(file, "%d", &l);
		fscanf(file, "%d", &graph[k - 1][l - 1]);
		graph[l - 1][k - 1] = graph[k - 1][l - 1];
	}
}

void initialization(int visit[], int distance[], int city)
{
	for (int i = 0; i < city; i++)
	{
		distance[i] = infinity;
		visit[i] = 0;
	}
	distance[first] = 0;
	visit[first] = 1;
}

void search(int *graph[], int visit[], int distance[], int city)
{
	int current = first;	// ������� �����
	bool flag = true;
	while(flag)
	{
		for(int i = 0; i < city; i++)
			if((graph[current][i] != 0) && (visit[i] == 0) && (distance[i] > distance[current] + graph[current][i]))	// ���� ���������� ������, ����� �� �������� � ���������� ������,
				distance[i] = distance[current] + graph[current][i];													// �� �������� �� ������� ���������� 
		int dist = infinity;
		flag = false;
		for(int i = 0; i < city; i++)	// ��������� ��� �� ������ ������
		{
			if((visit[i]) == 0 && (distance[i] < dist))
			{
				flag = true;
				current = i;
				dist = distance[i];
			}
		}
		visit[current] = 1;	// �������� ����� ����������
	}
}

void print(int distance[], int city)
{
	for(int j = 0; j < city; j++)
	{
		int min = infinity;
		int imin = 0;
		for(int i = 0; i < city; i++)
		{
			if((distance[i] < min) && (distance[i] >= 0))
			{
				min = distance[i];
				imin = i;
			}
		}
		printf("city number %d distance %d\n",imin + 1, min);
		distance[imin] = -1;
	}
}

int main()
{
	FILE *file;
	file = fopen("txt.txt","r");
	int city = read(file);	// ���������� �������
	int road = read(file);	// ���������� �����
	int **graph = new int*[city];
	for(int i = 0; i < city; i++)
		graph[i] = new int[city];
	initGraph(graph, city);	// ��������� ������� ���������� ������
	fillGraph(file, graph, road);	// ��������� ����� �����
	int *visit = new int[city];
	int *distance = new int[city];
	initialization(visit, distance, city);
	search(graph, visit, distance, city);	// ���� ����������� ����������
	print(distance, city);
	for (int i = 0; i < city; i++)
		delete[]graph[i];
	delete[]graph;
	delete[]visit;
	delete[]distance;
	fclose(file);
	cin.get();
	return 0;
}