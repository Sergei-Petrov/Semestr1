// author: Sergei Petrov

// email: sergei.petrov1994@gmail.com

// group є143

// homework є5 , task 2

// ѕо содержимому пам€ти вывести значение типа double в экспоненциальной форме: 
// sm*q^(Sp), где s -- знак мантиссы, m -- мантисса, q -- основание системы счислени€, 
// S -- знак пор€дка, p -- пор€док числа.

#include "stdafx.h"
#include <iostream>

using namespace std;

void binary(unsigned char *p, char string[], int j)
{
	int dec = *p;
	for(int i = 0; i < 8; i++)
	{
		string[j] = '0' + dec - dec/2*2;
		dec = dec/2;
		j--;
	}
}

int decimal(char string[])
{
	int razryad = 1;
	int rezult = 0;
	for(int i = 11; i > 0; i--)
	{
		if(string[i] == '1')
			rezult = rezult + razryad;
		razryad = razryad*2;
	}
	return rezult;
}

double decimal2(char string[])
{
	double razryad = 0.5;
	double rezult = 1.0;
	for(int i = 12; i < 64; i++)
	{
		if(string[i] == '1')
			rezult = rezult + razryad;
		razryad = razryad / 2;
	}
	return rezult;
}

void memory(double var, char string[])
{
	unsigned char *p = (unsigned char*)(&var);
	int j = 7;
	for(int i = 7; i >= 0; i--)
	{
		binary((p + i), string, j);
		j = j + 8;
	}
	string[64] = '\0';
	j = 63;
	while((string[j] != '1') && (j > 11))
	{
		string[j] = '\0';
		j--;
	}
}

void print(char string[])
{
	if (string[0] == '0')
		printf("+%f*2^(%d)", decimal2(string), decimal(string) - 1023);
	else
		printf("-%f*2^(%d)", decimal2(string), decimal(string) - 1023);
}

int main()
{
	double var = 0.0;
	cin >> var;
	char string[65];
	memory(var, string);
	print(string);
	scanf("%*s");
	return 0;
}