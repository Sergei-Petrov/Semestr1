#include "stdafx.h"

int main(int argc, _TCHAR* argv[])
{
	int a[28];
	for (int i = 0; i <= 27; i++)
	{
		a[i] = 0;
	}

	int b = 0;
	for (int i = 0; i <= 999; i++)
	{
		b = i/100 + (i/10) % 10 + i % 10;
		a[b]++;
	}

	int s = 0;
	for (int i = 0; i <= 27; i++)
	{
		s = s + a[i] * a[i];
	}
	printf("The sum of lucky tickets: %d", s);
	scanf("%d",&b);
	return 0;
}

